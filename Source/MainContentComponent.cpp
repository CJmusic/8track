//
//  MainContentComponent.cpp
//  8track - App
//
//  Created by Chris Joseph on 2022-03-27.
//

#include "MainContentComponent.h"


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
    Path p;

    Rectangle<float> r;
    r.setLeft(center.getX() - 2);
    r.setRight(center.getX() + 2);
    r.setTop(bounds.getY());
    g.setColour(Colours::black);
    g.fillRect(r);

    
    
}


void volumeSlider::paint(juce::Graphics &g)
{


}

juce::Rectangle<int> volumeSlider::getSliderBounds() const
{

}



juce::String volumeSlider::getDisplayString() const
{

}



