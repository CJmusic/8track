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



//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    MainContentComponent() //: slider1()
    {
        

//        slider1();
//        otherLookAndFeel.setColour (juce::Slider::thumbColourId, juce::Colours::red);
//        slider1.setLookAndFeel(&otherLookAndFeel);
//        slider1.setLookAndFeel(&otherLookAndFeel);

        
        header.setColour (juce::TextButton::buttonColourId, juce::Colours::cornflowerblue);
        header.setButtonText ("Header");
        addAndMakeVisible (header);

        footer.setColour (juce::TextButton::buttonColourId, juce::Colours::cornflowerblue);
        footer.setButtonText ("Footer");
        addAndMakeVisible (footer);

        track1.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track1.setButtonText ("track1");
        addAndMakeVisible (track1);
        
        
        addAndMakeVisible (slider1);
        slider1.setSliderStyle(juce::Slider::LinearVertical);
        
//        addAndMakeVisible(knob1);
//        knob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);

        volumeSlider slider1;
        addAndMakeVisible(lowFreqKnob1);
        lowFreqKnob1.setSliderStyle(juce::Slider::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(lowGainKnob1);
        lowGainKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(lowmidFreqKnob1);
        lowmidFreqKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(lowmidQKnob1);
        lowmidQKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(lowmidGainKnob1);
        lowmidGainKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(highmidFreqKnob1);
        highmidFreqKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(highmidQKnob1);
        highmidQKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(highmidGainKnob1);
        highmidGainKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(highFreqKnob1);
        highFreqKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(highGainKnob1);
        highGainKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(HPKnob1);
        HPKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(LPKnob1);
        LPKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(ThresholdKnob1);
        ThresholdKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(MakeupGainKnob1);
        MakeupGainKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(ReleaseKnob1);
        ReleaseKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        addAndMakeVisible(RatioKnob1);
        RatioKnob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        
        addAndMakeVisible(AutoGain1);
        
        
        addAndMakeVisible(arm1);
        addAndMakeVisible(mute1);
        addAndMakeVisible(solo1);
        
        

        track2.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track2.setButtonText ("track2");
        addAndMakeVisible (track2);

        track3.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track3.setButtonText ("track3");
        addAndMakeVisible (track3);
        
        track4.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track4.setButtonText ("track4");
        addAndMakeVisible (track4);
        
        track5.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track5.setButtonText ("track5");
        addAndMakeVisible (track5);
        
        track6.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track6.setButtonText ("track6");
        addAndMakeVisible (track6);
        
        track7.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track7.setButtonText ("track7");
        addAndMakeVisible (track7);

        track8.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        track8.setButtonText ("track8");
        addAndMakeVisible (track8);

        
        mainArea.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        mainArea.setButtonText ("mainArea");
        addAndMakeVisible (mainArea);


         setSize (1200, 820);
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::darkgrey);
    }

    void resized() override
    {
        auto area = getLocalBounds();

        auto headerFooterHeight = 36;
        header.setBounds (area.removeFromTop    (headerFooterHeight));
        footer.setBounds (area.removeFromBottom (headerFooterHeight));

        auto trackWidth = 110;
        auto trackHeight = getHeight() - 36*2;
        
        auto track1Bounds = area.removeFromLeft(trackWidth);
        track1.setBounds (track1Bounds);
        auto fader1Bounds = track1Bounds.removeFromBottom(250);
        slider1.setBounds(fader1Bounds);
        slider1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        
        
        track1Bounds.removeFromBottom(10);
        auto buttons1Bounds = track1Bounds.removeFromBottom(30);
        arm1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
        mute1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
        solo1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
        
        
        auto knob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
        knob1Bounds.setY(knob1Bounds.getY() - knob1Bounds.getHeight());
        knob1Bounds.setHeight(2*knob1Bounds.getHeight());
        lowFreqKnob1.setBounds(knob1Bounds);
        lowFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
        
        lowGainKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        lowGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        lowmidFreqKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        lowmidFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        lowmidQKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        lowmidQKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        lowmidGainKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        lowmidGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        highmidFreqKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        highmidFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        highmidQKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        highmidQKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        highmidGainKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        highmidGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        highFreqKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        highFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        highGainKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        highGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        HPKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        HPKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        LPKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        LPKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        ThresholdKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        ThresholdKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        MakeupGainKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        MakeupGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        ReleaseKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromLeft(trackWidth/2));
        ReleaseKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

        RatioKnob1.setBounds(track1Bounds.removeFromBottom((trackHeight -250)/20).removeFromRight(trackWidth/2));
        RatioKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    
//        knob1.setBounds(track1Bounds.removeFromBottom(trackHeight/10).removeFromLeft(trackWidth/1.5));
//        knob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
        
        track2.setBounds (area.removeFromLeft (trackWidth));
        track3.setBounds (area.removeFromLeft (trackWidth));
        track4.setBounds (area.removeFromLeft (trackWidth));
        track5.setBounds (area.removeFromLeft (trackWidth));
        track6.setBounds (area.removeFromLeft (trackWidth));
        track7.setBounds (area.removeFromLeft (trackWidth));
        track8.setBounds (area.removeFromLeft (trackWidth));
        
        mainArea.setBounds(area);

        
//        auto contentItemHeight = 24;
//        limeContent.setBounds       (area.removeFromTop (contentItemHeight)); // [1]
//        grapefruitContent.setBounds (area.removeFromTop (contentItemHeight));
//        lemonContent.setBounds      (area.removeFromTop (contentItemHeight));
//        orangeContent.setBounds     (area.removeFromTop (contentItemHeight));
    }

private:
//    juce::Rectangle track1bounds;
    
    juce::LookAndFeel_V4 otherLookAndFeel;
    
    juce::TextButton header;
    juce::TextButton footer;
    juce::TextButton mainArea;
    
//    juce::Slider slider1;
    volumeSlider slider1;
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

    
    juce::TextButton arm1;
    juce::TextButton mute1;
    juce::TextButton solo1;
    
    juce::TextButton track1;
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
