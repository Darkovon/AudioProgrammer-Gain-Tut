/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioProgrammerFirstPluginGainTutAudioProcessorEditor::AudioProgrammerFirstPluginGainTutAudioProcessorEditor (AudioProgrammerFirstPluginGainTutAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    mGainSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange (-60.0f, 0.0f, 0.01f);
    mGainSlider.setValue (-20.0f);
    mGainSlider.addListener (this);
    addAndMakeVisible (mGainSlider);


    setSize (200, 300);
}

AudioProgrammerFirstPluginGainTutAudioProcessorEditor::~AudioProgrammerFirstPluginGainTutAudioProcessorEditor()
{
}

//==============================================================================
void AudioProgrammerFirstPluginGainTutAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);

}

void AudioProgrammerFirstPluginGainTutAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor.. 
    mGainSlider.setBounds (getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
     
}

void AudioProgrammerFirstPluginGainTutAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
