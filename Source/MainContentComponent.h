#include <JuceHeader.h>


#pragma once
//ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts);

using Filter = juce::dsp::IIR::Filter<float>;

using CutFilter = juce::dsp::ProcessorChain<Filter, Filter, Filter, Filter>;

using MonoChain = juce::dsp::ProcessorChain<CutFilter, Filter, CutFilter>;

using Coefficients = Filter::CoefficientsPtr;

enum Slope
{
    Slope_12,
    Slope_24,
    Slope_36,
    Slope_48
};

struct ChainSettings
{
    float peakFreq{ 0 }, peakGainInDecibels{ 0 }, peakQuality{ 1.f };
    float lowCutFreq{ 0 }, highCutFreq { 0 };

    Slope lowCutSlope{ Slope::Slope_12 }, highCutSlope{ Slope::Slope_12 };
};

enum ChainPositions
{
    LowCut,
    Peak,
    HighCut
};

void updateCoefficients(Coefficients& old, const Coefficients& replacements);
ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts);

Coefficients makePeakFilter(const ChainSettings& chainSettings, double sampleRate);




struct  otherLookAndFeel : juce::LookAndFeel_V4
{
  void drawRotarySlider (juce::Graphics&,
                                  int x,
                                  int y,
                                  int width,
                                  int height,
                                  float sliderPosProportional,
                                  float rotaryStartAngle,
                                  float rotaryEndAngle,
                                  juce::Slider&) override;

    void     drawLinearSlider (juce::Graphics&,
                               int x,
                               int y,
                               int width,
                               int height,
                               float sliderPos,
                               float minSliderPos,
                               float maxSliderPos,
                               const juce::Slider::SliderStyle,
                               juce::Slider&) override;
    
};


struct RotarySliderWithLabels : juce::Slider
{
//  RotarySliderWithLabels(juce::RangedAudioParameter& rap, const juce::String& unitSuffix) : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox),
//  param(&rap),
//  suffix(unitSuffix)
    RotarySliderWithLabels()
  {
    setLookAndFeel(&lnf);
  }

  ~RotarySliderWithLabels()
  {
      setLookAndFeel(nullptr);
  }

  struct LabelPos
  {
      float pos;
      juce::String label;
  };

  juce::Array<LabelPos> labels;

  void paint(juce::Graphics& g) override;
  juce::Rectangle<int> getSliderBounds() const;
  int getTextHeight() const { return 14; }
  juce::String getDisplayString() const;

private:
  otherLookAndFeel lnf;


  juce::RangedAudioParameter* param;
  juce::String suffix;




};


struct volumeSlider : juce::Slider
{
//  volumeSlider(juce::RangedAudioParameter& rap, const juce::String& unitSuffix) : juce::Slider(juce::Slider::SliderStyle::LinearVertical, juce::Slider::TextEntryBoxPosition::NoTextBox),
//  param(&rap),
//  suffix(unitSuffix)
    volumeSlider()
  {
    setLookAndFeel(&lnf);
  }

  ~volumeSlider()
  {
      setLookAndFeel(nullptr);
  }

  struct LabelPos
  {
      float pos;
      juce::String label;
  };

  juce::Array<LabelPos> labels;

  void paint(juce::Graphics& g) override;
  juce::Rectangle<int> getSliderBounds() const;
  int getTextHeight() const { return 14; }
  juce::String getDisplayString() const;

private:
  otherLookAndFeel lnf;


  juce::RangedAudioParameter* param;
  juce::String suffix;


};

template<int Index, typename ChainType, typename CoefficientType>
void update(ChainType& chain, const CoefficientType& coefficients)
{
    updateCoefficients(chain.template get<Index>().coefficients, coefficients[Index]);
    chain.template setBypassed<Index>(false);
};


template<typename ChainType, typename CoefficientType>
void updateCutFilter(ChainType& leftLowCut,
                        const CoefficientType& cutCoefficients,
                        // const ChainSettings& chainSettings)
                        const Slope& lowCutSlope)

{
    
    leftLowCut.template setBypassed<0>(true);
    leftLowCut.template setBypassed<1>(true);
    leftLowCut.template setBypassed<2>(true);
    leftLowCut.template setBypassed<3>(true);

    switch( lowCutSlope )
    {
        case Slope_48:
        {
            update<3>(leftLowCut, cutCoefficients);
        }
        case Slope_36:
        {
            update<2>(leftLowCut, cutCoefficients);

        }
        case Slope_24:
        {
            update<1>(leftLowCut, cutCoefficients);

        }
        case Slope_12:
        {
            update<0>(leftLowCut, cutCoefficients);

        }
    }
}


inline auto makeLowCutFilter(const ChainSettings& chainSettings, double sampleRate)
{
    return juce::dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(chainSettings.lowCutFreq, sampleRate, 2 * (chainSettings.lowCutSlope + 1));
}


inline auto makeHighCutFilter(const ChainSettings& chainSettings, double sampleRate)
{
    return juce::dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(chainSettings.highCutFreq, sampleRate, 2 *(chainSettings.highCutSlope + 1));
}


ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts);

class Track : public juce::Component,
              public juce::AudioProcessor
{
public:
    Track();
    ~Track();
    void paint (juce::Graphics& g) override;
    void resized() override;
    void Input1SelectorChanged(juce::AudioDeviceSelectorComponent deviceManager);
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::AudioDeviceManager *deviceManager);
//    juce::dsp::AudioBlock<float> getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::AudioDeviceManager *deviceManager);
//    void updateFilters();
    
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::AudioProcessorValueTreeState apvts{*this, nullptr, "Parameters", createParameterLayout()};

    
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
    volumeSlider slider1;

private:
    MonoChain leftChain, rightChain;
    void updatePeakFilter(const ChainSettings& chainSettings);
    using Coefficients = Filter::CoefficientsPtr;
    // static void updateCoefficients(Coefficients& old, const Coefficients& replacements);

    void updateLowCutFilters(const ChainSettings& chainSettings);
    void updateHighCutFilters(const ChainSettings& chainSettings);

    void updateFilters();

    
    juce::LookAndFeel_V4 otherLookAndFeel;

    RotarySliderWithLabels lowFreqKnob1;
    RotarySliderWithLabels lowGainKnob1;
    RotarySliderWithLabels lowmidFreqKnob1;
    RotarySliderWithLabels lowmidQKnob1;
    RotarySliderWithLabels lowmidGainKnob1;
    RotarySliderWithLabels highmidFreqKnob1;
    RotarySliderWithLabels highmidQKnob1;
    RotarySliderWithLabels highmidGainKnob1;
    RotarySliderWithLabels highFreqKnob1;
    RotarySliderWithLabels highGainKnob1;
    RotarySliderWithLabels HPKnob1;
    RotarySliderWithLabels LPKnob1;
    RotarySliderWithLabels ThresholdKnob1;
    RotarySliderWithLabels MakeupGainKnob1;
    RotarySliderWithLabels ReleaseKnob1;
    RotarySliderWithLabels RatioKnob1;
    juce::TextButton AutoGain1;
    juce::ComboBox InputSelector1;
    
    juce::TextButton arm1;
    juce::TextButton mute1;
    juce::TextButton solo1;

};


//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    MainContentComponent();
    ~MainContentComponent();
    void paint (juce::Graphics& g) override;
    void resized() override;
    void settingsButtonPressed(juce::AudioDeviceSelectorComponent audioSetupComp);
    
    
    
    Track track1;
    Track track2;
    Track track3;
    Track track4;
    Track track5;
    Track track6;
    Track track7;
    Track track8;
    
    volumeSlider masterVolume;

    juce::Random random;

private:
//    juce::Rectangle track1bounds;

    juce::LookAndFeel_V4 otherLookAndFeel;

    
    juce::TextButton header;
    juce::TextButton footer;
    juce::TextButton mainArea;
    
//    juce::Slider slider1;
    
//    juce::TextButton track1;
//    juce::TextButton track2;
//    juce::TextButton track3;
//    juce::TextButton track4;
//    juce::TextButton track5;
//    juce::TextButton track6;
//    juce::TextButton track7;
//    juce::TextButton track8;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
