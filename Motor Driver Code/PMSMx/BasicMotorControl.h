/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Pavlo Milo Manovi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * @file	BasicMotorControl.c
 * @author 	Pavlo Manovi
 * @date	March 21st, 2014
 * @brief 	This library provides implementation of control methods for the DRV8301.
 *
 * This library provides implementation of a 3rd order LQG controller for a PMSM motor with
 * block commutation provided by hall effect sensors and a Change Notification interrupt system.
 * This LQG controller has the estimator and all other values exposed for experimentation.
 *
 * As of Sept. 2014 this method is included only as a method of integrating BLDC motors easily 
 * with the PMSMx module.  For use with the SUPER-Ball Bot and the geared Maxon Motors, please
 * use PMSM.c for motor control with the #SINE definition.
 * 
 * Note: To use this method of motor control CN must be set up.
 *
 */

#ifndef BASICMOTORCONTROL_H
#define	BASICMOTORCONTROL_H

typedef struct {
    uint16_t hallCount;
    uint16_t lastHallCount;
    uint16_t currentSpeed;
    uint16_t lastHallState;
} BasicMotorControlInfo;

enum {
    CW,
    CCW
};


/**
 * @brief Call this to update the controller at a rate of 3kHz.
 * @param speed Speed to set controller to follow.
 * 
 * It is required that the LQG controller which was characterized at a sample rate of n Hz is
 * run every n Hz with this function call.
 */
void SpeedControlStep(float speed);
#endif	/* BASICMOTORCONTROL_H */

