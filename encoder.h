/*
 * This File is Part Of : 
 *      ___                       ___           ___           ___           ___           ___                 
 *     /  /\        ___          /__/\         /  /\         /__/\         /  /\         /  /\          ___   
 *    /  /::\      /  /\         \  \:\       /  /:/         \  \:\       /  /:/_       /  /::\        /  /\  
 *   /  /:/\:\    /  /:/          \  \:\     /  /:/           \__\:\     /  /:/ /\     /  /:/\:\      /  /:/  
 *  /  /:/~/:/   /__/::\      _____\__\:\   /  /:/  ___   ___ /  /::\   /  /:/ /:/_   /  /:/~/::\    /  /:/   
 * /__/:/ /:/___ \__\/\:\__  /__/::::::::\ /__/:/  /  /\ /__/\  /:/\:\ /__/:/ /:/ /\ /__/:/ /:/\:\  /  /::\   
 * \  \:\/:::::/    \  \:\/\ \  \:\~~\~~\/ \  \:\ /  /:/ \  \:\/:/__\/ \  \:\/:/ /:/ \  \:\/:/__\/ /__/:/\:\  
 *  \  \::/~~~~      \__\::/  \  \:\  ~~~   \  \:\  /:/   \  \::/       \  \::/ /:/   \  \::/      \__\/  \:\ 
 *   \  \:\          /__/:/    \  \:\        \  \:\/:/     \  \:\        \  \:\/:/     \  \:\           \  \:\
 *    \  \:\         \__\/      \  \:\        \  \::/       \  \:\        \  \::/       \  \:\           \__\/
 *     \__\/                     \__\/         \__\/         \__\/         \__\/         \__\/                
 *
 * Copyright (c) Rinnegatamante <rinnegatamante@gmail.com>
 *
 */
 
#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <libk/stdlib.h>
#include <psp2/jpegenc.h>

typedef struct encoder{
	uint8_t isHwAccelerated;
	SceUID gpublock;
	void* tempbuf_addr;
	void* rescale_buffer;
	uint32_t in_size;
	uint32_t out_size;
	SceJpegEncoderContext context; // used only by sceJpegEnc
	uint32_t rowstride;            // Used only by libjpeg-turbo
}encoder;

SceUID encoderInit(int width, int height, int pitch, encoder* enc, uint8_t video_quality);
void encoderTerm(encoder* enc);
void* encodeARGB(encoder* enc, void* buffer, int pitch, int* outSize);
void encoderSetQuality(encoder* enc, uint8_t video_quality);
void encoderSetRescaler(encoder* enc, uint8_t use);

#endif