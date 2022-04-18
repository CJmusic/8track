//
//  Track.cpp
//  8track - App
//
//  Created by Chris Joseph on 2022-04-14.
//

#include "Track.h"

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

TrackEditor::TrackEditor(TrackProcessor& p)
: AudioProcessorEditor(&p), audioProcessor(),
slider1(*audioProcessor.apvts.getParameter("Volume")),
lowFreqKnob1(*audioProcessor.apvts.getParameter("low Freq")),
lowGainKnob1(*audioProcessor.apvts.getParameter("low Gain")),
lowmidFreqKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
lowmidQKnob1(*audioProcessor.apvts.getParameter("lowmid Q")),
lowmidGainKnob1(*audioProcessor.apvts.getParameter("lowmid Gain")),
highmidFreqKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
highmidQKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
highmidGainKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
highFreqKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
highGainKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
HPKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
LPKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
ThresholdKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
MakeupGainKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
ReleaseKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
RatioKnob1(*audioProcessor.apvts.getParameter("lowmid Freq")),
volumeSliderAttachment(audioProcessor.apvts, "Volume", slider1),
lowFreqKnobAttachment(audioProcessor.apvts, "low Freq", lowFreqKnob1),
lowGainKnobAttachment(audioProcessor.apvts, "low Gain", lowGainKnob1),
lowmidFreqKnobAttachment(audioProcessor.apvts, "lowmid Freq", lowmidFreqKnob1),
lowmidQKnobAttachment(audioProcessor.apvts, "lowmid Q", lowmidQKnob1),
lowmidGainKnobAttachment(audioProcessor.apvts, "lowmid Gain", lowmidGainKnob1),
highmidFreqKnobAttachment(audioProcessor.apvts, "highmid Freq", highmidFreqKnob1),
highmidQKnobAttachment(audioProcessor.apvts, "highmid Q", highmidQKnob1),
highmidGainKnobAttachment(audioProcessor.apvts, "highmid Gain", highmidGainKnob1),
highFreqKnobAttachment(audioProcessor.apvts, "high Freq", highFreqKnob1),
highGainKnobAttachment(audioProcessor.apvts, "high Gain", highGainKnob1),
HPKnobAttachment(audioProcessor.apvts, "HP Filter", HPKnob1),
LPKnobAttachment(audioProcessor.apvts, "LP Filter", LPKnob1),
ThresholdKnobAttachment(audioProcessor.apvts, "Threshold", ThresholdKnob1),
MakeupGainKnobAttachment(audioProcessor.apvts, "Makeup Gain", MakeupGainKnob1),
ReleaseKnobAttachment(audioProcessor.apvts, "Release", ReleaseKnob1),
RatioKnobAttachment(audioProcessor.apvts, "Ratio", RatioKnob1)
//AutoGainAttachment(audioProcessor.apvts, "HighCut Slope", AutoGain1)
{
//    addAndMakeVisible (slider1);
//    slider1.setSliderStyle(juce::Slider::LinearVertical);
    
//        addAndMakeVisible(knob1);
//        knob1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);

//    volumeSlider slider1;
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
TrackEditor::~TrackEditor()
{
    
};


void TrackEditor::resized()
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

void TrackEditor::paint(juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
};

//juce::dsp::AudioBlock<float> Track::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::AudioDeviceManager* deviceManager)
TrackProcessor::TrackProcessor() {
//    addAndMakeVisible(TrackEditor)

};

TrackProcessor::~TrackProcessor() {

};

void TrackProcessor::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill, juce::AudioDeviceManager* deviceManager)
{
//    return buffer;
//    auto level = slider1.getValue()/10;
    auto level = 1.0;
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
//    updateFilters();
}

const juce::String TrackProcessor::getName() const
{
//    return JucePlugin_Name;
    return "";
}

bool TrackProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TrackProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TrackProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TrackProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TrackProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TrackProcessor::getCurrentProgram()
{
    return 0;
}

void TrackProcessor::setCurrentProgram (int index)
{
}

const juce::String TrackProcessor::getProgramName (int index)
{
    return {};
}

void TrackProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TrackProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
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


void TrackProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TrackProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void TrackProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
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
bool TrackProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TrackProcessor::createEditor()
{
    return new TrackEditor(*this);
//     return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void TrackProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    juce::MemoryOutputStream mos(destData, true);
    apvts.state.writeToStream(mos);


}

void TrackProcessor::setStateInformation (const void* data, int sizeInBytes)
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

//    settings.lowCutFreq = apvts.getRawParameterValue("LowCut Freq")->load();
//    settings.highCutFreq = apvts.getRawParameterValue("HighCut Freq")->load();
//    settings.peakFreq = apvts.getRawParameterValue("Peak Freq")->load();
//    settings.peakGainInDecibels = apvts.getRawParameterValue("Peak Gain")->load();
//    settings.peakQuality = apvts.getRawParameterValue("Peak Quality")->load();
//    settings.lowCutSlope = static_cast<Slope>(apvts.getRawParameterValue("LowCut Slope")->load());
//    settings.highCutSlope = static_cast<Slope>(apvts.getRawParameterValue("HighCut Slope")->load());
    
    settings.Volume = apvts.getRawParameterValue("Volume")->load();
    settings.lowFreq = apvts.getRawParameterValue("low Freq")->load();
    settings.lowGain = apvts.getRawParameterValue("low Gain")->load();
    settings.lowmidFreq = apvts.getRawParameterValue("lowmid Freq")->load();
    settings.lowmidQ = apvts.getRawParameterValue("lowmid Q")->load();
    settings.lowmidGain = apvts.getRawParameterValue("lowmid Gain")->load();
    settings.highmidFreq = apvts.getRawParameterValue("highmid Freq")->load();
    settings.highmidQ = apvts.getRawParameterValue("highmid Q")->load();
    settings.highmidGain = apvts.getRawParameterValue("highmid Gain")->load();
    settings.highFreq = apvts.getRawParameterValue("high Freq") ->load();
    settings.highGain = apvts.getRawParameterValue("high Gain")->load();
    settings.HPFilter = apvts.getRawParameterValue("HP Filter")->load();
    settings.LPFilter = apvts.getRawParameterValue("LP Filter")->load();
    settings.Threshold = apvts.getRawParameterValue("Threshold")->load();
    settings.MakeupGain = apvts.getRawParameterValue("Makeup Gain")->load();
    settings.Release = apvts.getRawParameterValue("Release")->load();
    settings.Ratio = apvts.getRawParameterValue("Ratio")->load();

    return settings;
}

Coefficients makePeakFilter(const ChainSettings& chainSettings, double sampleRate)
{
//    return juce::dsp::IIR::Coefficients<float>::makePeakFilter(sampleRate,
//        chainSettings.peakFreq,
//        chainSettings.peakQuality,
//        juce::Decibels::decibelsToGain(chainSettings.peakGainInDecibels));
}

void TrackProcessor::updatePeakFilter(const ChainSettings& chainSettings)
{

//    auto peakCoefficients = makePeakFilter(chainSettings, getSampleRate());
//    updateCoefficients(leftChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);
//    updateCoefficients(rightChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);

}

void updateCoefficients(Coefficients &old, const Coefficients &replacements)
{
    *old = *replacements;
}

void TrackProcessor::updateLowCutFilters(const ChainSettings &chainSettings)
{

//    auto lowCutCoefficients = makeLowCutFilter(chainSettings, getSampleRate());
//
//    auto& leftLowCut = leftChain.get<ChainPositions::LowCut>();
//    updateCutFilter(leftLowCut, lowCutCoefficients, chainSettings.lowCutSlope);
//
//    auto& rightLowCut = rightChain.get<ChainPositions::LowCut>();
//    updateCutFilter(rightLowCut, lowCutCoefficients, chainSettings.lowCutSlope);

}


void TrackProcessor::updateHighCutFilters(const ChainSettings &chainSettings)
{

//    auto highCutCoefficients = makeHighCutFilter(chainSettings, getSampleRate());
//
//
//    auto& leftHighCut = leftChain.get<ChainPositions::HighCut>();
//    updateCutFilter(leftHighCut, highCutCoefficients, chainSettings.highCutSlope);
//
//    auto& rightHighCut = rightChain.get<ChainPositions::HighCut>();
//    updateCutFilter(rightHighCut, highCutCoefficients, chainSettings.highCutSlope);

}

void TrackProcessor::updateFilters()
{
    auto chainSettings = getChainSettings(apvts);

    updateLowCutFilters(chainSettings);
//    updatePeakFilter(chainSettings);
//    updateHighCutFilters(chainSettings);
}

juce::AudioProcessorValueTreeState::ParameterLayout TrackProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
    layout.add(std::make_unique<juce::AudioParameterFloat>("Volume", "Volume", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("low Freq", "low Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("low Gain", "low Gain", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("lowmid Freq", "lowmid Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("lowmid Q", "lowmid Q", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("lowmid Gain", "lowmid Gain", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("highmid Freq", "highmid Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("highmid Q", "highmid Q", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("highmid Gain", "highmid Gain", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("high Freq", "high Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("high Gain", "high Gain", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("HP Filter", "HP Filter", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("LP Filter", "LP Filter", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Threshold", "Threshold", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Makeup Gain", "Makeup Gain", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Release", "Release", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Ratio", "Ratio", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 20.f));
      

    return layout;
}


//==============================================================================
//// This creates new instances of the plugin..
//juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
//{
//    return new Track();
//}
 


std::vector<juce::Component*> TrackEditor::getComps()
{
  return
  {
      &slider1,
      &lowFreqKnob1,
      &lowGainKnob1,
      &lowmidFreqKnob1,
      &lowmidQKnob1,
      &lowmidGainKnob1,
      &highmidFreqKnob1,
      &highmidQKnob1,
      &highmidGainKnob1,
      &highFreqKnob1,
      &highGainKnob1,
      &HPKnob1,
      &LPKnob1,
      &ThresholdKnob1,
      &MakeupGainKnob1,
      &ReleaseKnob1,
      &RatioKnob1,
      &AutoGain1
  };
  }
