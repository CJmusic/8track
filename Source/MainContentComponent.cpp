//
//  MainContentComponent.cpp
//  8track - App
//
//  Created by Chris Joseph on 2022-03-27.
//

#include "MainContentComponent.h"


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

    
    
    track1Bounds.removeFromBottom(10);
    auto buttons1Bounds = track1Bounds.removeFromBottom(30);
    arm1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
    mute1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
    solo1.setBounds(buttons1Bounds.removeFromLeft(trackWidth/3));
    
    
    auto lowFreqKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    lowFreqKnob1Bounds.setY(lowFreqKnob1Bounds.getY() - lowFreqKnob1Bounds.getHeight());
    lowFreqKnob1Bounds.setHeight(2*lowFreqKnob1Bounds.getHeight());
    lowFreqKnob1.setBounds(lowFreqKnob1Bounds);
    lowFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
    
    
    auto lowGainKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    lowGainKnob1Bounds.setY(lowGainKnob1Bounds.getY() - lowGainKnob1Bounds.getHeight());
    lowGainKnob1Bounds.setHeight(2*lowGainKnob1Bounds.getHeight());
    lowGainKnob1.setBounds(lowGainKnob1Bounds);
    lowGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);
    
    auto lowmidFreqKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    lowmidFreqKnob1Bounds.setY(lowmidFreqKnob1Bounds.getY() - lowmidFreqKnob1Bounds.getHeight());
    lowmidFreqKnob1Bounds.setHeight(2*lowmidFreqKnob1Bounds.getHeight());
    lowmidFreqKnob1.setBounds(lowmidFreqKnob1Bounds);
    lowmidFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto lowmidQKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    lowmidQKnob1Bounds.setY(lowmidQKnob1Bounds.getY() - lowmidQKnob1Bounds.getHeight());
    lowmidQKnob1Bounds.setHeight(2*lowmidQKnob1Bounds.getHeight());
    lowmidQKnob1.setBounds(lowmidQKnob1Bounds);
    lowmidQKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto lowmidGainKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    lowmidGainKnob1Bounds.setY(lowmidGainKnob1Bounds.getY() - lowmidGainKnob1Bounds.getHeight());
    lowmidGainKnob1Bounds.setHeight(2*lowmidGainKnob1Bounds.getHeight());
    lowmidGainKnob1.setBounds(lowmidGainKnob1Bounds);
    lowmidGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highmidFreqKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    highmidFreqKnob1Bounds.setY(highmidFreqKnob1Bounds.getY() - highmidFreqKnob1Bounds.getHeight());
    highmidFreqKnob1Bounds.setHeight(2*highmidFreqKnob1Bounds.getHeight());
    highmidFreqKnob1.setBounds(highmidFreqKnob1Bounds);
    highmidFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highmidQKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    highmidQKnob1Bounds.setY(highmidQKnob1Bounds.getY() - highmidQKnob1Bounds.getHeight());
    highmidQKnob1Bounds.setHeight(2*highmidQKnob1Bounds.getHeight());
    highmidQKnob1.setBounds(highmidQKnob1Bounds);
    highmidQKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highmidGainKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    highmidGainKnob1Bounds.setY(highmidGainKnob1Bounds.getY() - highmidGainKnob1Bounds.getHeight());
    highmidGainKnob1Bounds.setHeight(2*highmidGainKnob1Bounds.getHeight());
    highmidGainKnob1.setBounds(highmidGainKnob1Bounds);
    highmidGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highFreqKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    highFreqKnob1Bounds.setY(highFreqKnob1Bounds.getY() - highFreqKnob1Bounds.getHeight());
    highFreqKnob1Bounds.setHeight(2*highFreqKnob1Bounds.getHeight());
    highFreqKnob1.setBounds(highFreqKnob1Bounds);
    highFreqKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto highGainKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    highGainKnob1Bounds.setY(highGainKnob1Bounds.getY() - highGainKnob1Bounds.getHeight());
    highGainKnob1Bounds.setHeight(2*highGainKnob1Bounds.getHeight());
    highGainKnob1.setBounds(highGainKnob1Bounds);
    highGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto HPKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    HPKnob1Bounds.setY(HPKnob1Bounds.getY() - HPKnob1Bounds.getHeight());
    HPKnob1Bounds.setHeight(2*HPKnob1Bounds.getHeight());
    HPKnob1.setBounds(HPKnob1Bounds);
    HPKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto LPKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    LPKnob1Bounds.setY(LPKnob1Bounds.getY() - LPKnob1Bounds.getHeight());
    LPKnob1Bounds.setHeight(2*LPKnob1Bounds.getHeight());
    LPKnob1.setBounds(LPKnob1Bounds);
    LPKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto ThresholdKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    ThresholdKnob1Bounds.setY(ThresholdKnob1Bounds.getY() - ThresholdKnob1Bounds.getHeight());
    ThresholdKnob1Bounds.setHeight(2*ThresholdKnob1Bounds.getHeight());
    ThresholdKnob1.setBounds(ThresholdKnob1Bounds);
    ThresholdKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto MakeupGainKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    MakeupGainKnob1Bounds.setY(MakeupGainKnob1Bounds.getY() - MakeupGainKnob1Bounds.getHeight());
    MakeupGainKnob1Bounds.setHeight(2*MakeupGainKnob1Bounds.getHeight());
    MakeupGainKnob1.setBounds(MakeupGainKnob1Bounds);
    MakeupGainKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto ReleaseKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
    ReleaseKnob1Bounds.setY(ReleaseKnob1Bounds.getY() - ReleaseKnob1Bounds.getHeight());
    ReleaseKnob1Bounds.setHeight(2*ReleaseKnob1Bounds.getHeight());
    ReleaseKnob1.setBounds(ReleaseKnob1Bounds);
    ReleaseKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);

    auto RatioKnob1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromRight(trackWidth/2);
    RatioKnob1Bounds.setY(RatioKnob1Bounds.getY() - RatioKnob1Bounds.getHeight());
    RatioKnob1Bounds.setHeight(2*RatioKnob1Bounds.getHeight());
    RatioKnob1.setBounds(RatioKnob1Bounds);
    RatioKnob1.setTextBoxStyle(juce::Slider::NoTextBox, 0, 0, 0);


    auto AutoGain1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20).removeFromLeft(trackWidth/2);
//        AutoGain1Bounds.setY(AutoGain1Bounds.getY() - AutoGain1Bounds.getHeight());
//        AutoGain1Bounds.setHeight(2*AutoGain1Bounds.getHeight());
    AutoGain1.setBounds(AutoGain1Bounds);

    auto InputSelector1Bounds = track1Bounds.removeFromBottom((trackHeight-250)/20);
    InputSelector1.setBounds(InputSelector1Bounds);
};

void Track::paint(juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
}

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
    
    addAndMakeVisible(track1);
    

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
MainContentComponent::~MainContentComponent()
{
    
}
void MainContentComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
}

void MainContentComponent::resized() 
{
    auto area = getLocalBounds();

    auto headerFooterHeight = 36;
    header.setBounds (area.removeFromTop    (headerFooterHeight));
    footer.setBounds (area.removeFromBottom (headerFooterHeight));

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
    
    mainArea.setBounds(area);

    
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



