//
//  MainContentComponent.cpp
//  8track - App
//
//  Created by Chris Joseph on 2022-03-27.
//

#include "MainContentComponent.h"
//void Track::Input1SelectorChanged(juce::AudioDeviceSelectorComponent deviceManager)
// {
//    auto* device = deviceManager.getCurrentAudioDevice();
//    auto input = device->getActiveInputChannels();
//     switch (InputSelector1.getSelectedId())
//     {
//         case 1: input = device->getActiveInputChannels(); break;
//     }
//
////     textLabel.setFont (textFont);
// }

Track::Track()
{
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
    addAndMakeVisible(InputSelector1);
    
    
    InputSelector1.addItem("Item 1", 1);
    
//
//    InputSelector1.onChange = [this] { Track::Input1SelectorChanged(audioSetupComp); };
//    InputSelector1.setSelectedId (1);

    
    
    addAndMakeVisible(arm1);
    addAndMakeVisible(mute1);
    addAndMakeVisible(solo1);
    
};
Track::~Track()
{
    
};


void Track::resized()
{
    auto track1Bounds = getLocalBounds();
    auto trackWidth = 110;
    auto trackHeight = getHeight() - 36*2;

    auto fader1Bounds = track1Bounds.removeFromBottom(250);
    slider1.setBounds(fader1Bounds);
    slider1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto knobWidth  = trackWidth/2;
    auto knobHeight = (trackHeight-250)/18;
    
    track1Bounds.removeFromBottom(10);
    auto buttons1Bounds = track1Bounds.removeFromBottom(30);
    arm1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
    mute1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
    solo1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
    
    
    auto lowFreqKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    lowFreqKnob1Bounds.setY(lowFreqKnob1Bounds.getY() - lowFreqKnob1Bounds.getHeight());
    lowFreqKnob1Bounds.setHeight(2*lowFreqKnob1Bounds.getHeight());
    lowFreqKnob1.setBounds(lowFreqKnob1Bounds);
    lowFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
    
    
    auto lowGainKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    lowGainKnob1Bounds.setY(lowGainKnob1Bounds.getY() - lowGainKnob1Bounds.getHeight());
    lowGainKnob1Bounds.setHeight(2*lowGainKnob1Bounds.getHeight());
    lowGainKnob1.setBounds(lowGainKnob1Bounds);
    lowGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
    
    auto lowmidFreqKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    lowmidFreqKnob1Bounds.setY(lowmidFreqKnob1Bounds.getY() - lowmidFreqKnob1Bounds.getHeight());
    lowmidFreqKnob1Bounds.setHeight(2*lowmidFreqKnob1Bounds.getHeight());
    lowmidFreqKnob1.setBounds(lowmidFreqKnob1Bounds);
    lowmidFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto lowmidQKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    lowmidQKnob1Bounds.setY(lowmidQKnob1Bounds.getY() - lowmidQKnob1Bounds.getHeight());
    lowmidQKnob1Bounds.setHeight(2*lowmidQKnob1Bounds.getHeight());
    lowmidQKnob1.setBounds(lowmidQKnob1Bounds);
    lowmidQKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto lowmidGainKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    lowmidGainKnob1Bounds.setY(lowmidGainKnob1Bounds.getY() - lowmidGainKnob1Bounds.getHeight());
    lowmidGainKnob1Bounds.setHeight(2*lowmidGainKnob1Bounds.getHeight());
    lowmidGainKnob1.setBounds(lowmidGainKnob1Bounds);
    lowmidGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highmidFreqKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    highmidFreqKnob1Bounds.setY(highmidFreqKnob1Bounds.getY() - highmidFreqKnob1Bounds.getHeight());
    highmidFreqKnob1Bounds.setHeight(2*highmidFreqKnob1Bounds.getHeight());
    highmidFreqKnob1.setBounds(highmidFreqKnob1Bounds);
    highmidFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highmidQKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    highmidQKnob1Bounds.setY(highmidQKnob1Bounds.getY() - highmidQKnob1Bounds.getHeight());
    highmidQKnob1Bounds.setHeight(2*highmidQKnob1Bounds.getHeight());
    highmidQKnob1.setBounds(highmidQKnob1Bounds);
    highmidQKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highmidGainKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    highmidGainKnob1Bounds.setY(highmidGainKnob1Bounds.getY() - highmidGainKnob1Bounds.getHeight());
    highmidGainKnob1Bounds.setHeight(2*highmidGainKnob1Bounds.getHeight());
    highmidGainKnob1.setBounds(highmidGainKnob1Bounds);
    highmidGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highFreqKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    highFreqKnob1Bounds.setY(highFreqKnob1Bounds.getY() - highFreqKnob1Bounds.getHeight());
    highFreqKnob1Bounds.setHeight(2*highFreqKnob1Bounds.getHeight());
    highFreqKnob1.setBounds(highFreqKnob1Bounds);
    highFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highGainKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    highGainKnob1Bounds.setY(highGainKnob1Bounds.getY() - highGainKnob1Bounds.getHeight());
    highGainKnob1Bounds.setHeight(2*highGainKnob1Bounds.getHeight());
    highGainKnob1.setBounds(highGainKnob1Bounds);
    highGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto HPKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    HPKnob1Bounds.setY(HPKnob1Bounds.getY() - HPKnob1Bounds.getHeight());
    HPKnob1Bounds.setHeight(2*HPKnob1Bounds.getHeight());
    HPKnob1.setBounds(HPKnob1Bounds);
    HPKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto LPKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    LPKnob1Bounds.setY(LPKnob1Bounds.getY() - LPKnob1Bounds.getHeight());
    LPKnob1Bounds.setHeight(2*LPKnob1Bounds.getHeight());
    LPKnob1.setBounds(LPKnob1Bounds);
    LPKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto ThresholdKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    ThresholdKnob1Bounds.setY(ThresholdKnob1Bounds.getY() - ThresholdKnob1Bounds.getHeight());
    ThresholdKnob1Bounds.setHeight(2*ThresholdKnob1Bounds.getHeight());
    ThresholdKnob1.setBounds(ThresholdKnob1Bounds);
    ThresholdKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto MakeupGainKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    MakeupGainKnob1Bounds.setY(MakeupGainKnob1Bounds.getY() - MakeupGainKnob1Bounds.getHeight());
    MakeupGainKnob1Bounds.setHeight(2*MakeupGainKnob1Bounds.getHeight());
    MakeupGainKnob1.setBounds(MakeupGainKnob1Bounds);
    MakeupGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto ReleaseKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
    ReleaseKnob1Bounds.setY(ReleaseKnob1Bounds.getY() - ReleaseKnob1Bounds.getHeight());
    ReleaseKnob1Bounds.setHeight(2*ReleaseKnob1Bounds.getHeight());
    ReleaseKnob1.setBounds(ReleaseKnob1Bounds);
    ReleaseKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto RatioKnob1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromRight(knobWidth);
    RatioKnob1Bounds.setY(RatioKnob1Bounds.getY() - RatioKnob1Bounds.getHeight());
    RatioKnob1Bounds.setHeight(2*RatioKnob1Bounds.getHeight());
    RatioKnob1.setBounds(RatioKnob1Bounds);
    RatioKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);


    auto AutoGain1Bounds = track1Bounds.removeFromBottom(knobHeight).removeFromLeft(knobWidth);
//        AutoGain1Bounds.setY(AutoGain1Bounds.getY() - AutoGain1Bounds.getHeight());
//        AutoGain1Bounds.setHeight(2*AutoGain1Bounds.getHeight());
    AutoGain1.setBounds(AutoGain1Bounds);

    auto InputSelector1Bounds = track1Bounds.removeFromBottom(knobHeight);
    InputSelector1.setBounds(InputSelector1Bounds);
};

void Track::paint(juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
};

//juce::dsp::AudioBlock<float> Track::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::AudioDeviceManager* deviceManager)
void Track::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::AudioDeviceManager* deviceManager)
{
//    return buffer;
    auto level = slider1.getValue()/10;
    auto* device = deviceManager->getCurrentAudioDevice();
    auto activeInputChannels = device->getActiveInputChannels();
    auto activeOutputChannels = device->getActiveOutputChannels();
    
    auto maxInputChannels  = activeInputChannels .getHighestBit() + 1;
    auto maxOutputChannels = activeOutputChannels.getHighestBit() + 1;
    
    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        // Get a pointer to the start sample in the buffer for this audio output channel
        auto* buffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);

        // Fill the required number of samples with noise between -0.125 and +0.125
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample){
            buffer[sample] += (random.nextFloat()*level);
        }
    }
}

const juce::String Track::getName() const
{
//    return JucePlugin_Name;
    return "";
}

bool Track::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Track::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Track::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Track::getTailLengthSeconds() const
{
    return 0.0;
}

int Track::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Track::getCurrentProgram()
{
    return 0;
}

void Track::setCurrentProgram (int index)
{
}

const juce::String Track::getProgramName (int index)
{
    return {};
}

void Track::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Track::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..


    juce::dsp::ProcessSpec spec;

    spec.maximumBlockSize = samplesPerBlock;

    spec.numChannels = 1;
    spec.sampleRate = sampleRate;

//    leftChain.prepare(spec);
//    rightChain.prepare(spec);

    updateFilters();


}


void Track::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Track::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Track::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    updateFilters();

    // audio gets processed below

   juce::dsp::AudioBlock<float> block(buffer);

   auto leftBlock = block.getSingleChannelBlock(0);
   auto rightBlock = block.getSingleChannelBlock(1);

   juce::dsp::ProcessContextReplacing<float> leftContext(leftBlock);
   juce::dsp::ProcessContextReplacing<float> rightContext(rightBlock);

   leftChain.process(leftContext);
   rightChain.process(rightContext);
}

//==============================================================================
bool Track::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Track::createEditor()
{
//    return new juce::AudioProcessorEditor (*this);
     return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void Track::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    juce::MemoryOutputStream mos(destData, true);
    apvts.state.writeToStream(mos);


}

void Track::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.


    auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
    if (tree.isValid())
    {
        apvts.replaceState(tree);
        updateFilters();
    }


}

ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts)
{
    ChainSettings settings;


    settings.lowCutFreq = apvts.getRawParameterValue("LowCut Freq")->load();
    settings.highCutFreq = apvts.getRawParameterValue("HighCut Freq")->load();
    settings.peakFreq = apvts.getRawParameterValue("Peak Freq")->load();
    settings.peakGainInDecibels = apvts.getRawParameterValue("Peak Gain")->load();
    settings.peakQuality = apvts.getRawParameterValue("Peak Quality")->load();
    settings.lowCutSlope = static_cast<Slope>(apvts.getRawParameterValue("LowCut Slope")->load());
    settings.highCutSlope = static_cast<Slope>(apvts.getRawParameterValue("HighCut Slope")->load());

    return settings;
}

Coefficients makePeakFilter(const ChainSettings& chainSettings, double sampleRate)
{
    return juce::dsp::IIR::Coefficients<float>::makePeakFilter(sampleRate,
        chainSettings.peakFreq,
        chainSettings.peakQuality,
        juce::Decibels::decibelsToGain(chainSettings.peakGainInDecibels));
}

void Track::updatePeakFilter(const ChainSettings& chainSettings)
{

    auto peakCoefficients = makePeakFilter(chainSettings, getSampleRate());
    updateCoefficients(leftChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);
    updateCoefficients(rightChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);

}

void updateCoefficients(Coefficients &old, const Coefficients &replacements)
{
    *old = *replacements;
}

void Track::updateLowCutFilters(const ChainSettings &chainSettings)
{

    auto lowCutCoefficients = makeLowCutFilter(chainSettings, getSampleRate());

    auto& leftLowCut = leftChain.get<ChainPositions::LowCut>();
    updateCutFilter(leftLowCut, lowCutCoefficients, chainSettings.lowCutSlope);

    auto& rightLowCut = rightChain.get<ChainPositions::LowCut>();
    updateCutFilter(rightLowCut, lowCutCoefficients, chainSettings.lowCutSlope);

}


void Track::updateHighCutFilters(const ChainSettings &chainSettings)
{

    auto highCutCoefficients = makeHighCutFilter(chainSettings, getSampleRate());


    auto& leftHighCut = leftChain.get<ChainPositions::HighCut>();
    updateCutFilter(leftHighCut, highCutCoefficients, chainSettings.highCutSlope);

    auto& rightHighCut = rightChain.get<ChainPositions::HighCut>();
    updateCutFilter(rightHighCut, highCutCoefficients, chainSettings.highCutSlope);

}

void Track::updateFilters()
{
    auto chainSettings = getChainSettings(apvts);

    updateLowCutFilters(chainSettings);
    updatePeakFilter(chainSettings);
    updateHighCutFilters(chainSettings);
}

juce::AudioProcessorValueTreeState::ParameterLayout Track::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    layout.add(std::make_unique<juce::AudioParameterFloat>("LowCut Freq", "LowCut Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));

    layout.add(std::make_unique<juce::AudioParameterFloat>("HighCut Freq", "HighCut Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20000.f));

    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Freq", "Peak Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 750.f));

    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Gain", "Peak Gain", juce::NormalisableRange<float>(-24.f, 24.f, 0.5f, 1.f), 0.0f));

    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Quality", "Peak Quality", juce::NormalisableRange<float>(0.1f, 10.f, 0.05f, 1.f), 1.0f));

    juce::StringArray stringArray;
    for( int i = 0; i < 4; ++i )
    {
        juce::String str;
        str << (12 + i * 12);
        str << "db/Oct";
        stringArray.add(str);
    }

    layout.add(std::make_unique<juce::AudioParameterChoice>("LowCut Slope", "LowCut Slope", stringArray, 0));
    layout.add(std::make_unique<juce::AudioParameterChoice>("HighCut Slope", "HighCut Slope", stringArray, 0));

      

    return layout;
}


//==============================================================================
//// This creates new instances of the plugin..
//juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
//{
//    return new Track();
//}
 




MainContentComponent::MainContentComponent()
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

//    track1.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
//        track1.setButtonText ("track1");
//        addAndMakeVisible (track1);
    
    addAndMakeVisible (track1);
    addAndMakeVisible (track2);
    addAndMakeVisible (track3);
    addAndMakeVisible (track4);
    addAndMakeVisible (track5);
    addAndMakeVisible (track6);
    addAndMakeVisible (track7);
    addAndMakeVisible (track8);

    addAndMakeVisible (masterVolume);
    masterVolume.setSliderStyle(juce::Slider::LinearVertical);
    masterVolume.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    mainArea.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
    mainArea.setButtonText ("mainArea");
    addAndMakeVisible (mainArea);


     setSize (1200, 820);
}
MainContentComponent::~MainContentComponent()
{
    
}
void MainContentComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
}

void MainContentComponent::resized() 
{
    auto area = getLocalBounds();

    auto headerFooterHeight = 36;
//    header.setBounds (area.removeFromTop    (headerFooterHeight));
//    footer.setBounds (area.removeFromBottom (headerFooterHeight));

    (area.removeFromTop    (headerFooterHeight));
    (area.removeFromBottom (headerFooterHeight));

    auto trackWidth = 110;
    auto trackHeight = getHeight() - 36*2;
    
//        knob1.setBounds(track1Bounds.removeFromBottom(trackHeight/10).removeFromLeft(trackWidth/1.5));
//        knob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
    
    track1.setBounds (area.removeFromLeft (trackWidth));
    track2.setBounds (area.removeFromLeft (trackWidth));
    track3.setBounds (area.removeFromLeft (trackWidth));
    track4.setBounds (area.removeFromLeft (trackWidth));
    track5.setBounds (area.removeFromLeft (trackWidth));
    track6.setBounds (area.removeFromLeft (trackWidth));
    track7.setBounds (area.removeFromLeft (trackWidth));
    track8.setBounds (area.removeFromLeft (trackWidth));
    
//    mainArea.setBounds(area);
//    area.removeFromBottom(headerFooterHeight);
//    transportControls.setBounds(area.removeFromBottom(50));
    (area.removeFromBottom(50));
    
    masterVolume.setBounds (area.removeFromBottom(250).removeFromLeft(110));
    
    
    
//        auto contentItemHeight = 24;
//        limeContent.setBounds       (area.removeFromTop (contentItemHeight)); // [1]
//        grapefruitContent.setBounds (area.removeFromTop (contentItemHeight));
//        lemonContent.setBounds      (area.removeFromTop (contentItemHeight));
//        orangeContent.setBounds     (area.removeFromTop (contentItemHeight));
}


void MainContentComponent::settingsButtonPressed(juce::AudioDeviceSelectorComponent audioSetupComp)
{
    addAndMakeVisible(audioSetupComp);

}



void otherLookAndFeel::drawRotarySlider(juce::Graphics & g,
                                                    int x,
                                                    int y,
                                                    int width,
                                                    int height,
                                                    float sliderPosProportional,
                                                    float rotaryStartAngle,
                                                    float rotaryEndAngle,
                                                    juce::Slider & slider)
{
  using namespace juce;

  auto bounds = Rectangle<float>(x, y, width, height);
  
  g.setColour(Colour(juce::Colours::red));
  g.fillEllipse(bounds);
    
  g.setColour(Colour(juce::Colours::lightgrey));
  g.drawEllipse(bounds, 5.f);

  if( auto* rswl = dynamic_cast<RotarySliderWithLabels*>(&slider))
  {
    auto center = bounds.getCentre();
    Path p;

    Rectangle<float> r;
    r.setLeft(center.getX() - 2);
    r.setRight(center.getX() + 2);
    r.setTop(bounds.getY());
      r.setBottom(center.getY() - 4);
//    r.setBottom(center.getY() - rswl->getTextHeight() * 1.5);

    p.addRoundedRectangle(r,2.f);
      
    jassert(rotaryStartAngle < rotaryEndAngle);

    auto sliderAngRad = jmap(sliderPosProportional, 0.f, 1.f, rotaryStartAngle, rotaryEndAngle);

    p.applyTransform(AffineTransform().rotated(sliderAngRad, center.getX(), center.getY()));

    g.fillPath(p);

    g.setFont(rswl->getTextHeight());
    auto text = rswl->getDisplayString();
    auto strWidth = g.getCurrentFont().getStringWidth(text);

    r.setSize(strWidth + 4, rswl->getTextHeight() + 2);
    r.setCentre(bounds.getCentre());

//    g.setColour(Colours::black);
//    g.fillRect(r);
//
//    g.setColour(Colours::white);
//    g.drawFittedText(text, r.toNearestInt(), juce::Justification::centred,1);


  }

  // auto center = bounds.getCentre();

  // Path p;

  // Rectangle<float> r;
  // r.setLeft(center.getX() - 2);
  // r.setRight(center.getY() + 2);
  // r.setTop(bounds.getY());
  // r.setBottom(center.getY());

  // p.addRectangle(r);

  // jassert(rotaryStartAngle < rotaryEndAngle);

  // auto sliderAngRad = jmap(sliderPosProportional, 0.f, 1.f, rotaryStartAngle, rotaryEndAngle);

  // p.applyTransform(AffineTransform().rotated(sliderAngRad, center.getX(), center.getY()));

  // g.fillPath(p);

}


void RotarySliderWithLabels::paint(juce::Graphics &g)
{
  using namespace juce;

  auto startAng = degreesToRadians(180.f + 45.f);
  auto endAng = degreesToRadians(180.f - 45.f) + MathConstants<float>::twoPi;

  auto range = getRange();
  
  auto sliderBounds = getSliderBounds();
//    auto sliderBounds = getLocalBounds();


    
    //DEBUGGING - Draw boxes around Knobs
//   g.setColour(Colours::red);
//   g.drawRect(getLocalBounds());
    //DEBUGGING ENDS
    
    
//   g.setColour(Colours::yellow);
//   g.drawRect(sliderBounds);

  getLookAndFeel().drawRotarySlider(g,
                                    sliderBounds.getX(),
                                    sliderBounds.getY(),
                                    sliderBounds.getWidth(),
                                    sliderBounds.getHeight(),
                                    jmap(getValue(), range.getStart(), range.getEnd(), 0.0, 1.0),
                                    startAng,
                                    endAng,
                                    *this);

  auto center = sliderBounds.toFloat().getCentre();
  auto radius = sliderBounds.getWidth() * 0.5f;

  g.setColour(Colour(0u, 172u, 1u));
  g.setFont(getTextHeight());

  auto numChoices = labels.size();
  for( int i = 0; i < numChoices; ++i )
  {
    auto pos = labels[i].pos;
    jassert(0.f <= pos);
    jassert(pos <= 1.f);

    auto ang = jmap(pos, 0.f, 1.f, startAng, endAng);

    auto c = center.getPointOnCircumference(radius + getTextHeight()* 0.5f + 1, ang);

    Rectangle<float> r;
    auto str = labels[i].label;
    r.setSize(g.getCurrentFont().getStringWidth(str), getTextHeight());
    r.setCentre(c);
    r.setY(r.getY() + getTextHeight());

    g.drawFittedText(str, r.toNearestInt(), juce::Justification::centred, 1);

  }

}

juce::Rectangle<int> RotarySliderWithLabels::getSliderBounds() const
{
  // return getLocalBounds();
  auto bounds = getLocalBounds();
  auto size = juce::jmin(bounds.getWidth(), bounds.getHeight());

    size /= 1.5;

  juce::Rectangle<int> r;
  r.setSize(size, size);
  r.setCentre(bounds.getCentreX(), bounds.getCentreY());
//  r.setY(2);

  return r;

}



juce::String RotarySliderWithLabels::getDisplayString() const
{
//    if (auto* choiceParam = dynamic_cast<juce::AudioParameterChoice*>(param))
//        return choiceParam->getCurrentChoiceName();

    juce::String str;
//    bool addK = false;
//
//    if (auto* floatParam = dynamic_cast<juce::AudioParameterFloat*>(param))
//    {
//        float val = getValue();
//        if (val > 999.f)
//        {
//            val /= 1000.f;
//            addK = true;
//        }
//        str = juce::String(val, (addK ? 2 : 0));
//    }
//    else
//    {
////        jassertfalse;
//    }
//
//    if (suffix.isNotEmpty())
//    {
//        str << " ";
//        if (addK)
//            str << "k";
//        str << suffix;
//    }
    return str;
}



void otherLookAndFeel::drawLinearSlider(juce::Graphics&g,
                                                         int x,
                                                         int y,
                                                         int width,
                                                         int height,
                                                         float sliderPos,
                                                         float minSliderPos,
                                                         float maxSliderPos,
                                                         const juce::Slider::SliderStyle,
                                                         juce::Slider&)
{
    using namespace juce;

    auto bounds = Rectangle<float>(x, y, width, height);
    auto center = bounds.getCentre();
    
//    Rectangle<float> r;
//    r.setLeft(center.getX() - 2);
//    r.setRight(center.getX() + 2);
//    r.setTop(bounds.getY());
//    g.setColour(Colours::red);
//    g.fillRect(r);

    
    
}


void volumeSlider::paint(juce::Graphics &g)
{
    using namespace juce;
    auto range = getRange();
    auto bounds = getLocalBounds();
    auto sliderBounds = getSliderBounds();
    auto value = getValue();
    
//    auto sliderPos =
    // need to make a sliderPos variable, which normalizes
    // value into something to do with the bounds
    // it can't change the positions of the
    
    
//     g.setColour(Colours::red);
//     g.drawRect(getLocalBounds());
     g.setColour(Colours::black);
     g.drawRect(sliderBounds);
     g.fillRect(sliderBounds);
    
    
    getLookAndFeel().drawLinearSlider(g,
                      sliderBounds.getX(),
                      sliderBounds.getY(),
                      sliderBounds.getWidth(),
                      sliderBounds.getHeight(),
                      jmap(getValue(), range.getStart(), range.getEnd(), 0.0, 1.0),
                      0.0,
                      1.0,
                      juce::Slider::LinearVertical,
                                      *this);

    auto center = sliderBounds.toFloat().getCentre();
    auto radius = sliderBounds.getWidth() * 0.5f;

    auto thumbWidth = bounds.getWidth() - 10;//getSliderThumbRadius(*this);
    auto thumbHeight = bounds.getHeight()/5;
    
    Rectangle<float> thumb;
    
    thumb.setLeft(center.getX() - thumbWidth/2);
    thumb.setRight(center.getX() + thumbWidth/2);
    thumb.setTop(bounds.getY() + thumbHeight);
    thumb.setBottom(center.getY() - thumbHeight);
    thumb.setCentre(center.getX(), sliderBounds.getY() - value*22 + 235);
    g.setColour(Colours::black);
    g.fillRect(thumb);

}

juce::Rectangle<int> volumeSlider::getSliderBounds() const
{
    auto bounds = getLocalBounds();
    auto size = bounds.getHeight();


    juce::Rectangle<int> r;
    r.setSize(size/40, size);
    r.setCentre(bounds.getCentreX(), bounds.getCentreY());

    return r;
}



juce::String volumeSlider::getDisplayString() const
{
//    if (auto* choiceParam = dynamic_cast<juce::AudioParameterChoice*>(param))
//        return choiceParam->getCurrentChoiceName();
//
    juce::String str;
//    bool addK = false;
//
//    if (auto* floatParam = dynamic_cast<juce::AudioParameterFloat*>(param))
//    {
//        float val = getValue();
//        if (val > 999.f)
//        {
//            val /= 1000.f;
//            addK = true;
//        }
//        str = juce::String(val, (addK ? 2 : 0));
//    }
//    else
//    {
//        jassertfalse;
//    }
//
//    if (suffix.isNotEmpty())
//    {
//        str << " ";
//        if (addK)
//            str << "k";
//        str << suffix;
//    }
//    return str;
    return str;
}



