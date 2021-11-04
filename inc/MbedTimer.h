/*
The MIT License (MIT)

Copyright (c) 2017 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef CODAL_MBED_TIMER_H
#define CODAL_MBED_TIMER_H

#include "codal-core/inc/types/Event.h"
#include "codal-core/inc/driver-models/Timer.h"
#include "mbed.h"

namespace mb=mbed;

namespace codal
{
    namespace _mbed
    {
        class _LowLevelTimer : public codal::LowLevelTimer {
			public:
			
			
			_LowLevelTimer() : LowLevelTimer(1) {
				
			}
			/**
			 * Enables this timer instance and begins counting
			 **/
			virtual int enable() {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Enables the IRQ of this timer instance
			 **/
			virtual int enableIRQ() {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Disables this timer instance and stops counting
			 **/
			virtual int disable() {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Disables the IRQ of this timer instance
			 **/
			virtual int disableIRQ() {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Resets the counter of this timer.
			 **/
			virtual int reset() {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Sets the mode of the timer
			 *
			 * @param t the timer mode to use. Underlying hardware should be configured appropriately.
			 **/
			virtual int setMode(TimerMode t) {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Sets the compare value of a capture compare register in the underlying hardware
			 *
			 * @param channel the channel to load the value into.
			 *
			 * @param value the value to load into the capture compare register
			 **/
			virtual int setCompare(uint8_t channel, uint32_t value) {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Offsets the compare value of a capture compare register in the underlying hardware
			 *
			 * @param channel the channel to offset by value.
			 *
			 * @param value the value to offset the capture compare register by.
			 **/
			virtual int offsetCompare(uint8_t channel, uint32_t value) {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Disables the interrupt for the given channel, and sets the value to 0.
			 *
			 * @param channel the channel to clear
			 **/
			virtual int clearCompare(uint8_t channel) {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Returns the counter value of the underlying hardware.
			 **/
			virtual uint32_t captureCounter() {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Sets the frequency of the timer based on a speed given in Khz.
			 *
			 * @param speedKHz the speed of the timer in KHz.
			 **/
			virtual int setClockSpeed(uint32_t speedKHz) {
				//TQD_TODO
				
				return 0;
			}

			/**
			 * Sets the resolution of the timer counter.
			 *
			 * @param t the TimerBitMode value to use.
			 **/
			virtual int setBitMode(TimerBitMode t) {
				//TQD_TODO
				
				return 0;
			}
			
		};
		
		
		class Timer : public codal::Timer
        {
            // TQD_TODO
			uint32_t period;

            mb::Timer timer;
            mb::Timeout timeout;
			uint32_t interrupState;
			
			//codal::_mbed::_LowLevelTimer llt;

            void triggered();

        public:

            /**
              * Constructor for an instance of Timer1.
              *
              * @param id The id to use for the message bus when transmitting events.
              */
            Timer();

            /**
             * request to the physical timer implementation code to provide a trigger callback at the given time.
             * note: it is perfectly legitimate for the implementation to trigger before this time if convenient.
             * @param t Indication that t time units (typically microsends) have elapsed.
             */
            virtual void triggerIn(CODAL_TIMESTAMP t);

            /**
             * request to the physical timer implementation code to trigger immediately.
             */
            virtual void syncRequest();
			
			virtual int enableInterrupts();
			virtual int disableInterrupts();
			
			void sync(CODAL_TIMESTAMP t);
        };
    }
}

#endif
