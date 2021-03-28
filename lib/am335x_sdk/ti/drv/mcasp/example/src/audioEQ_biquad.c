/*
 * audioEQ_biquad.c
 *
 * This file contains the Biquad implementation used for audio equalization
 *
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

/** \file     audioEQ_biquad.c
 *
 *  \brief    Biquad filterer implementation
 *
 *  This file contains the implementation of biquad filters used 
 *  for audio equalization
 *
 *  References:
 *  http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt
 *  http://www.earlevel.com/main/2012/11/26/biquad-c-source-code/ 
 */
 
#include <math.h>
#include "audioEQ_biquad.h"
#define PI 3.14159

void Biquad_initParams(BIQUAD_T *filter) {
    filter->type = bq_type_lowpass;
    filter->a0 = 1.0;
    filter->a1 = filter->a2 = filter->b1 = filter->b2 = 0.0;
    filter->Fc = 0.50;
    filter->Q = 0.707;
    filter->peakGain = 0.0;
    filter->z1 = filter->z2 = 0.0;
}

void Biquad_setPeakGain(BIQUAD_T *filter,double peakGainDB) {
    filter->peakGain = peakGainDB;
    Biquad_computeCoeff(filter);
}

void Biquad_setBiquad(BIQUAD_T *filter, int type, double Fc, double Q, double peakGainDB) {
    filter->type = type;
    filter->Q = Q;
    filter->Fc = Fc;
    Biquad_setPeakGain(filter,peakGainDB);
}

void Biquad_computeCoeff(BIQUAD_T *filter) {
    double normFactor;
    double A = pow(10, fabs(filter->peakGain) / 20.0);
    double K = tan(PI * filter->Fc);
    switch (filter->type) {
        case bq_type_lowpass:
            normFactor = 1 / (1 + K / filter->Q + K * K);
            filter->a0 = K * K * normFactor;
            filter->a1 = 2 * filter->a0;
            filter->a2 = filter->a0;
            filter->b1 = 2 * (K * K - 1) * normFactor;
            filter->b2 = (1 - K / filter->Q + K * K) * normFactor;
            break;
            
        case bq_type_highpass:
            normFactor = 1 / (1 + K / filter->Q + K * K);
            filter->a0 = 1 * normFactor;
            filter->a1 = -2 * filter->a0;
            filter->a2 = filter->a0;
            filter->b1 = 2 * (K * K - 1) * normFactor;
            filter->b2 = (1 - K / filter->Q + K * K) * normFactor;
            break;
            
        case bq_type_bandpass:
            normFactor = 1 / (1 + K / filter->Q + K * K);
            filter->a0 = K / filter->Q * normFactor;
            filter->a1 = 0;
            filter->a2 = -filter->a0;
            filter->b1 = 2 * (K * K - 1) * normFactor;
            filter->b2 = (1 - K / filter->Q + K * K) * normFactor;
            break;
            
        case bq_type_notch:
            normFactor = 1 / (1 + K / filter->Q + K * K);
            filter->a0 = (1 + K * K) * normFactor;
            filter->a1 = 2 * (K * K - 1) * normFactor;
            filter->a2 = filter->a0;
            filter->b1 = filter->a1;
            filter->b2 = (1 - K / filter->Q + K * K) * normFactor;
            break;
            
        case bq_type_peak:
            if (filter->peakGain >= 0) {    // boost
                normFactor = 1 / (1 + 1/filter->Q * K + K * K);
                filter->a0 = (1 + A/filter->Q * K + K * K) * normFactor;
                filter->a1 = 2 * (K * K - 1) * normFactor;
                filter->a2 = (1 - A/filter->Q * K + K * K) * normFactor;
                filter->b1 = filter->a1;
                filter->b2 = (1 - 1/filter->Q * K + K * K) * normFactor;
            }
            else {    // cut
                normFactor = 1 / (1 + A/filter->Q * K + K * K);
                filter->a0 = (1 + 1/filter->Q * K + K * K) * normFactor;
                filter->a1 = 2 * (K * K - 1) * normFactor;
                filter->a2 = (1 - 1/filter->Q * K + K * K) * normFactor;
                filter->b1 = filter->a1;
                filter->b2 = (1 - A/filter->Q * K + K * K) * normFactor;
            }
            break;
        case bq_type_lowshelf:
            if (filter->peakGain >= 0) {    // boost
                normFactor = 1 / (1 + sqrt(2) * K + K * K);
                filter->a0 = (1 + sqrt(2*A) * K + A * K * K) * normFactor;
                filter->a1 = 2 * (A * K * K - 1) * normFactor;
                filter->a2 = (1 - sqrt(2*A) * K + A * K * K) * normFactor;
                filter->b1 = 2 * (K * K - 1) * normFactor;
                filter->b2 = (1 - sqrt(2) * K + K * K) * normFactor;
            }
            else {    // cut
                normFactor = 1 / (1 + sqrt(2*A) * K + A * K * K);
                filter->a0 = (1 + sqrt(2) * K + K * K) * normFactor;
                filter->a1 = 2 * (K * K - 1) * normFactor;
                filter->a2 = (1 - sqrt(2) * K + K * K) * normFactor;
                filter->b1 = 2 * (A * K * K - 1) * normFactor;
                filter->b2 = (1 - sqrt(2*A) * K + A * K * K) * normFactor;
            }
            break;
        case bq_type_highshelf:
            if (filter->peakGain >= 0) {    // boost
                normFactor = 1 / (1 + sqrt(2) * K + K * K);
                filter->a0 = (A + sqrt(2*A) * K + K * K) * normFactor;
                filter->a1 = 2 * (K * K - A) * normFactor;
                filter->a2 = (A - sqrt(2*A) * K + K * K) * normFactor;
                filter->b1 = 2 * (K * K - 1) * normFactor;
                filter->b2 = (1 - sqrt(2) * K + K * K) * normFactor;
            }
            else {    // cut
                normFactor = 1 / (A + sqrt(2*A) * K + K * K);
                filter->a0 = (1 + sqrt(2) * K + K * K) * normFactor;
                filter->a1 = 2 * (K * K - 1) * normFactor;
                filter->a2 = (1 - sqrt(2) * K + K * K) * normFactor;
                filter->b1 = 2 * (K * K - A) * normFactor;
                filter->b2 = (A - sqrt(2*A) * K + K * K) * normFactor;
            }
            break;
    }
    
    return;
}

void Biquad_applyFilter32(BIQUAD_T *filter, int *input, int *output, int BufferSize){
	int i;
    float inSample;
	double outSample;
	for (i = 0; i<BufferSize; i++){
		inSample = (float)input[i];
		outSample = Biquad_process(filter, inSample);
		output[i] = (int)outSample;
	}
}

void Biquad_applyFilter16(BIQUAD_T *filter, short *input, short *output, int BufferSize){
	int i;
    float inSample;
    double outSample;
	for (i = 0; i<BufferSize; i++){
		inSample = (float)input[i];
		outSample = Biquad_process(filter, inSample);
		output[i] = (short)outSample;
	}
}


