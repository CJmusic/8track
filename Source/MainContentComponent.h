#include <JuceHeader.h>


#pragma once


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


class Track : public juce::Component
{
public:
    Track();
    ~Track();
    void paint (juce::Graphics& g) override;
    void resized() override;
    
    volumeSlider slider1;

private:
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

private:
//    juce::Rectangle track1bounds;

    juce::LookAndFeel_V4 otherLookAndFeel;
    
    
    juce::TextButton header;
    juce::TextButton footer;
    juce::TextButton mainArea;
    
//    juce::Slider slider1;
    
//    juce::TextButton track1;
    juce::TextButton track2;
    juce::TextButton track3;
    juce::TextButton track4;
    juce::TextButton track5;
    juce::TextButton track6;
    juce::TextButton track7;
    juce::TextButton track8;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
