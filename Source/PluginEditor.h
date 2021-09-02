/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ImageFromFilePluginExAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ImageFromFilePluginExAudioProcessorEditor (ImageFromFilePluginExAudioProcessor&);
    ~ImageFromFilePluginExAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void openButtonClicked();
    void clearButtonClicked();
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ImageFromFilePluginExAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImageFromFilePluginExAudioProcessorEditor)

    juce::Image background;
    juce::TextButton openButton;
    juce::TextButton clearButton;

    std::unique_ptr<juce::FileChooser> chooser;

};
