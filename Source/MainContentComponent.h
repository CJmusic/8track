#pragma once

//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    MainContentComponent()
    {
        header.setColour (juce::TextButton::buttonColourId, juce::Colours::cornflowerblue);
        header.setButtonText ("Header");
        addAndMakeVisible (header);

        footer.setColour (juce::TextButton::buttonColourId, juce::Colours::cornflowerblue);
        footer.setButtonText ("Footer");
        addAndMakeVisible (footer);

        sidebar.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        sidebar.setButtonText ("Sidebar");
        addAndMakeVisible (sidebar);

        limeContent.setColour (juce::TextButton::buttonColourId, juce::Colours::lime);
        addAndMakeVisible (limeContent);

        grapefruitContent.setColour (juce::TextButton::buttonColourId, juce::Colours::yellowgreen);
        addAndMakeVisible (grapefruitContent);

        lemonContent.setColour (juce::TextButton::buttonColourId, juce::Colours::yellow);
        addAndMakeVisible (lemonContent);

        orangeContent.setColour (juce::TextButton::buttonColourId, juce::Colours::orange);
        addAndMakeVisible (orangeContent);

        // setSize (400, 400);
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

        auto sidebarWidth = 80;
        sidebar.setBounds (area.removeFromLeft (sidebarWidth)); // [2]

        auto contentItemHeight = 24;
        limeContent.setBounds       (area.removeFromTop (contentItemHeight)); // [1]
        grapefruitContent.setBounds (area.removeFromTop (contentItemHeight));
        lemonContent.setBounds      (area.removeFromTop (contentItemHeight));
        orangeContent.setBounds     (area.removeFromTop (contentItemHeight));
    }

private:
    juce::TextButton header;
    juce::TextButton sidebar;

    juce::TextButton limeContent;
    juce::TextButton grapefruitContent;
    juce::TextButton lemonContent;
    juce::TextButton orangeContent;
    juce::TextButton footer;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
