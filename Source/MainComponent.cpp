#include "MainComponent.h"
#include "MainContentComponent.h"



//==============================================================================
MainComponent::MainComponent() : audioSetupComp(deviceManager,
                                                0,
                                                256,
                                                0,
                                                256,
                                                false,
                                                false,
                                                false,
                                                false)
{
    
//    MainContentComponent content = MainContentComponent();
//    juce::Component content = MainContentComponent::MainContentComponent();
//    addAndMakeVisible(header);
    addAndMakeVisible(content);
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
//    setSize (400, 400);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    

}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    auto level = content.masterVolume.getValue()/10;
    auto* device = deviceManager.getCurrentAudioDevice();
    auto activeInputChannels = device->getActiveInputChannels();
    auto activeOutputChannels = device->getActiveOutputChannels();
    
    auto maxInputChannels  = activeInputChannels .getHighestBit() + 1;
    auto maxOutputChannels = activeOutputChannels.getHighestBit() + 1;
    
    
//    auto level =  MainComponent::MainContentComponent::volumeSlider;
//    auto level = slider1.getValue()/10;
//    volumeSlider.getValue(); // not sure if this is volumeSlider appropriate
//     auto level =  1.0;

    
//
//    for (auto channel = 0; channel < maxOutputChannels; ++channel)
//    {
//        if ((! activeOutputChannels[channel]) || maxInputChannels == 0)
//        {
//            bufferToFill.buffer->clear( channel, bufferToFill.startSample, bufferToFill.numSamples);
//        }
//        else
//        {
//            auto actualInputChannel = channel % maxInputChannels; // [1]
//
//            if (! activeInputChannels[channel]) // [2]
//            {
//                bufferToFill.buffer->clear (channel, bufferToFill.startSample, bufferToFill.numSamples);
//            }
//            else // [3]
//            {
//                auto* inBuffer = bufferToFill.buffer->getReadPointer (actualInputChannel,
//                                                                      bufferToFill.startSample);
//                auto* outBuffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);
//
//                for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
//                    outBuffer[sample] = inBuffer[sample] * level;
//            }
//        }
//    }

    // Your audio-processing code goes here!
//    auto buffer1 = content.track1.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer2 = content.track2.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer3 = content.track3.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer4 = content.track4.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer5 = content.track5.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer6 = content.track6.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer7 = content.track7.getNextAudioBlock(bufferToFill, &deviceManager);
//    auto buffer8 = content.track8.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track1.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track2.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track3.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track4.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track5.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track6.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track7.getNextAudioBlock(bufferToFill, &deviceManager);
    content.track8.getNextAudioBlock(bufferToFill, &deviceManager);

    // For more details, see the help for AudioProcessor::getNextAudioBlock()
//    juce::dsp::AudioBlock<float> outBuffer;

    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        // Get a pointer to the start sample in the buffer for this audio output channel
        auto* buffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);

        // Fill the required number of samples with noise between -0.125 and +0.125
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
            buffer[sample] = level*(content.random.nextFloat() * 0.25f - 0.125f);
    }

    

//    auto masterBuffer = level*(buffer1 + buffer2 + buffer3 + buffer4 + buffer5 + buffer6 + buffer7 + buffer8);
    // For more details, see the help for AudioProcessor::getNextAudioBlock()
}
    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
//    bufferToFill.clearActiveBufferRegion();


void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll (juce::Colours::lightblue);


    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    auto area = getLocalBounds();
    audioSetupComp.setBounds( area.removeFromRight(500));
//
//    auto headerFooterHeight = 100;
//    header.setBounds (area.removeFromTop    (headerFooterHeight));
//    footer.setBounds (area.removeFromBottom (headerFooterHeight));
    

}
