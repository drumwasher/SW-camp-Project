/*
 * encoder.h
 *
 *  Created on: 2024. 2. 21.
 *      Author: JINKYU
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "Ifx_Types.h"
#include "IfxPort.h"


void initEncoder(void);
boolean getEncoderAValue(void);
boolean getEncoderBValue(void);


#endif /* ENCODER_H_ */
