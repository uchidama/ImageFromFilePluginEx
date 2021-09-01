/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ImageFromFilePluginExAudioProcessorEditor::ImageFromFilePluginExAudioProcessorEditor (ImageFromFilePluginExAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (640, 480);
    
    juce::File f ("/Users/masatoshi.uchida/JuceProjects/ImageFromFilePluginEx/switch_lite.jpg");
    background = juce::ImageFileFormat::loadFrom(f);

}

ImageFromFilePluginExAudioProcessorEditor::~ImageFromFilePluginExAudioProcessorEditor()
{
}

//==============================================================================
void ImageFromFilePluginExAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.drawImageAt(background, 0, 0);

    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ImageFromFilePluginExAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
