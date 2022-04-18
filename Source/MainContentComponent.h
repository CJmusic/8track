#include <JuceHeader.h>
#include "Track.h"

//==============================================================================
#pragma once

class MainContentComponent   : public juce::Component
{
public:
    MainContentComponent();
    ~MainContentComponent();
    void paint (juce::Graphics& g) override;
    void resized() override;
    void settingsButtonPressed(juce::AudioDeviceSelectorComponent audioSetupComp);
    
    
    
    TrackEditor track1Editor;
    
    TrackProcessor track1;
    TrackProcessor track2;
    TrackProcessor track3;
    TrackProcessor track4;
    TrackProcessor track5;
    TrackProcessor track6;
    TrackProcessor track7;
    TrackProcessor track8;
    
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
