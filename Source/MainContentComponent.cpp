//
//  MainContentComponent.cpp
//  8track - App
//
//  Created by Chris Joseph on 2022-03-27.
//

#include "MainContentComponent.h"



MainContentComponent::MainContentComponent() :
track1Editor(track1)
//track1(),
//track1(const TrackEditor &p),
//track2(TrackProcessor &p),
//track2(const TrackEditor &p),
//track3(TrackProcessor &p),
//track3(const TrackEditor &p),
//track4(TrackProcessor &p),
//track4(const TrackEditor &p),
//track5(TrackProcessor &p),
//track5(const TrackEditor &p),
//track6(TrackProcessor &p),
//track6(const TrackEditor &p),
//track7(TrackProcessor &p),
//track7(const TrackEditor &p),
//track8(TrackProcessor &p),
//track8(const TrackEditor &p)
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
    addAndMakeVisible(track1Editor);
    addAndMakeVisible (track2);
    addAndMakeVisible (track3);
    addAndMakeVisible (track4);
    addAndMakeVisible (track5);
    addAndMakeVisible (track6);
    addAndMakeVisible (track7);
    addAndMakeVisible (track8);
    
//    track1.paint();

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



