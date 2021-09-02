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
    
    addAndMakeVisible (&openButton);
    openButton.setButtonText ("Open...");
    openButton.onClick = [this] { openButtonClicked(); };

    addAndMakeVisible (&clearButton);
    clearButton.setButtonText ("Clear");
    clearButton.onClick = [this] { clearButtonClicked(); };
    
}

ImageFromFilePluginExAudioProcessorEditor::~ImageFromFilePluginExAudioProcessorEditor()
{
}

void ImageFromFilePluginExAudioProcessorEditor::clearButtonClicked()
{
    const juce::Rectangle<int> area(0,0,640,480);
    background.clear(area);
    
    this->repaint();
}

void ImageFromFilePluginExAudioProcessorEditor::openButtonClicked()
{
    chooser = std::make_unique<juce::FileChooser> ("Select a Wave file to play...",
                                                   juce::File{},
                                                   "*.jpg, *.png");
    auto chooserFlags = juce::FileBrowserComponent::openMode
                      | juce::FileBrowserComponent::canSelectFiles;

    chooser->launchAsync (chooserFlags, [this] (const juce::FileChooser& fc)
    {
        auto file = fc.getResult();

        if (file != juce::File{})                                                      
        {
            background = juce::ImageFileFormat::loadFrom(file);
            this->repaint();
        }
    });
}

//==============================================================================
void ImageFromFilePluginExAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.drawImageAt(background, 0, 0);
}

void ImageFromFilePluginExAudioProcessorEditor::resized()
{
    
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    openButton.setBounds (10, 10, getWidth() - 20, 20);
    clearButton.setBounds (10, 40, getWidth() - 20, 20);

}
