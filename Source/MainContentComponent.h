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

        
        addAndMakeVisible (slider1);
        slider1.setSliderStyle(juce::Slider::LinearVertical);
        
        addAndMakeVisible(knob1);
        

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
        
        auto track1Bounds = area.removeFromLeft (trackWidth);
        track1.setBounds (track1Bounds);
        auto fader1Bounds = track1Bounds.removeFromBottom  (250);
        slider1.setBounds(fader1Bounds);
        
        
        
        knob1.setBounds(track1Bounds);

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
    RotarySliderWithLabels knob1;

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
