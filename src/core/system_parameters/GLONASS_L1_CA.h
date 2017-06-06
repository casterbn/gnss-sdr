/*!
 * \file GLONASS_L1_CA.h
 * \brief  Defines system parameters for GLONASS L1 C/A signal and NAV data
 * \author Damian Miralles, 2017. dmiralles2009(at)gmail.com
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2015  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_GLONASS_L1_CA_H_
#define GNSS_SDR_GLONASS_L1_CA_H_

#include <vector>
#include <utility> // std::pair
#include "MATH_CONSTANTS.h"
#include "gnss_frequencies.h"

// Physical constants
const double GLONASS_C_m_s                  = SPEED_OF_LIGHT;       //!< The speed of light, [m/s]
const double GLONASS_C_m_ms                 = 299792.4580;          //!< The speed of light, [m/ms]
const double GLONASS_PI                     = 3.1415926535898;      //!< Pi as defined in IS-GPS-200E
const double GLONASS_TWO_PI                 = 6.283185307179586;    //!< 2Pi as defined in IS-GPS-200E
const double GLONASS_OMEGA_EARTH_DOT        = 7.292115e-5;          //!< Earth rotation rate, [rad/s]
const double GLONASS_GM                     = 398600.4418e9;        //!< Universal gravitational constant times the mass of the Earth, [km^3/s^2]
const double GLONASS_fM_a                   = 0.35e9;               //!< Gravitational constant of atmosphere [m^3/s^2]
const double GLONASS_SEMI_MAJOR_AXIS        = 6378136;              //!< Semi-major axis of Earth [m]
const double GLONASS_FLATTENING             = 1/29825784;           //!< Flattening parameter
const double GLONASS_GRAVITY                = 97803284;             //!< Equatorial acceleration of gravity [mGal]
const double GLONASS_GRAVITY_CORRECTION     = 0.87;                 //!< Correction to acceleration of gravity at sea-level due to Atmosphere[мGal]
const double GLONASS_J2                     = 1082625.75e-9;        //!< Second zonal harmonic of the geopotential
const double GLONASS_J4                     = -2370.89e-9;          //!<Fourth zonal harmonic of the geopotential
const double GLONASS_J6                     = 6.08e-9;              //!< Sixth zonal harmonic of the geopotential
const double GLONASS_J8                     = 1.40e-11;             //!< Eighth zonal harmonic of the geopotential
const double GLONASS_U0                     = 62636861.4;           //!< Normal potential at surface of common terrestrial ellipsoid [m^2/s^2]
const double GLONASS_C20                    = -1082.63e-6;          //!< Second zonal coefficient of spherical harmonic expansion
const double GLONASS_EARTH_RADIUS           = 6378.136;             //!< Equatorial radius of Earth [km]
const double GLONASS_EARTH_INCLINATION      = 23°26'33''            //!< Mean inclination of ecliptic to equator (23°26'33'').

const double GLONASS_TAU_0                  = -334°19′46′′,40;
const double GLONASS_TAU_1                  = 4069°02′02′′,52;

const double GLONASS_MOON_Q0                = -63°53′43′′,41;
const double GLONASS_MOON_Q1                = 477198°50′56′′,79;
const double GLONASS_MOON_OMEGA_0           = 259°10′59′′,79;
const double GLONASS_MOON_OMEGA_1           = -1934°08′31′′,23;
const double GLONASS_MOON_GM                = 4902.835;             //!< Lunar gravitational constant [km^3/s^2]
const double GLONASS_MOON_SEMI_MAJOR_AXIS   = 3.84385243e5;         //!< Semi-major axis of lunar orbit [km];
const double GLONASS_MOON_ECCENTRICITY      = 0.054900489;          //!< Eccentricity of lunar orbit
const double GLONASS_MOON_INCLINATION       = 5°08'43.4''           //!< Inclination of lunar orbit to ecliptic plane (5°08'43.4'')

const double GLONASS_SUN_OMEGA              = 281°13′15′′,0 + 6189′′, 03Т;
const double GLONASS_SUN_Q0                 = 358°28′33′′,04;
const double GLONASS_SUN_Q1                 = 129596579′′,10;
const double GLONASS_SUN_GM                 = 0.1325263e12;       //!< Solar gravitational constant [km^3/s^2]
const double GLONASS_SUN_SEMI_MAJOR_AXIS    = 1.49598e8;          //!< Semi-major axis of solar orbit [km];
const double GLONASS_SUN_ECCENTRICITY       = 0.016719;           //!< Eccentricity of solar orbit

// carrier and code frequencies
const double GLONASS_L1_FREQ_HZ              = FREQ1_GLO;     //!< L1 [Hz]
const double GLONASS_L1_DFREQ_HZ             = DFRQ1_GLO;     //!< Freq Bias for GLONASS L1 [Hz]
const double GLONASS_L1_CA_CODE_RATE_HZ      = 0.511e6;       //!< GLONASS L1 C/A code rate [chips/s]
const double GLONASS_L1_CA_CODE_LENGTH_CHIPS = 511.0;         //!< GLONASS L1 C/A code length [chips]
const double GLONASS_L1_CA_CODE_PERIOD       = 0.001;         //!< GLONASS L1 C/A code period [seconds]
const double GLONASS_L1_CA_CHIP_PERIOD       = 1.9569e-06;    //!< GLONASS L1 C/A chip period [seconds]

const double GLONASS_STARTOFFSET_ms = 68.802; //[ms] Initial sign. travel time (this cannot go here)

// OBSERVABLE HISTORY DEEP FOR INTERPOLATION
const int GLONASS_L1_CA_HISTORY_DEEP = 100;

// NAVIGATION MESSAGE DEMODULATION AND DECODING

#define GLONASS_CA_PREAMBLE {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0}
const int GLONASS_CA_PREAMBLE_LENGTH_BITS = 30;
const int GLONASS_CA_PREAMBLE_LENGTH_SYMBOLS = 300;
const double GLONASS_CA_PREAMBLE_DURATION_S = 0.3;
const int GLONASS_CA_TELEMETRY_RATE_BITS_SECOND = 50;   //!< NAV message bit rate [bits/s]
const int GLONASS_CA_TELEMETRY_SYMBOLS_PER_BIT = 10;
const int GLONASS_CA_TELEMETRY_RATE_SYMBOLS_SECOND = GLONASS_CA_TELEMETRY_RATE_BITS_SECOND*GLONASS_CA_TELEMETRY_SYMBOLS_PER_BIT;   //!< NAV message bit rate [symbols/s]

const int GLONASS_GNAV_WORD_LENGTH = 4;         //!< \TODO cHECK this, size is not integer bte size
const int GLONASS_GNAV_FRAME_LENGTH = 40;       //!< \TODO GPS_WORD_LENGTH x 10 = 40 bytes
const int GLONASS_GNAV_FRAME_BITS = 1725;       //!< Number of chips per frame in the GNAV message  15 strings*(85 data bits + 30 time mark bits)[bits]
const int GLONASS_GNAV_FRAME_SECONDS = 30;      //!< Subframe duration [seconds]
const int GLONASS_GNAV_FRAME_MS = 30000;        //!< Subframe duration [seconds]
const int GLONASS_GNAV_STRING_BITS = 115;       //!< Number of bits per string in the GNAV message (85 data bits + 30 time mark bits) [bits]

// GLONASS GNAV NAVIGATION MESSAGE STRUCTURE
// NAVIGATION MESSAGE FIELDS POSITIONS (from IS-GPS-200E Appendix II)

// FRAME 1-4
// COMMON FIELDS
const std::vector<std::pair<int,int>> STRING_ID({{2,4}});
const std::vector<std::pair<int,int>> KX({{78,8}});
//STRING 1
const std::vector<std::pair<int,int>> P1({{8,2}});
const std::vector<std::pair<int,int>> T_K({{10,12}});
const std::vector<std::pair<int,int>> X_N_DOT ({{22,24}});
const std::vector<std::pair<int,int>> X_N_DOT_DOT ({{46,5}});
const std::vector<std::pair<int,int>> X_N({{51,27}});

//STRING 2
const std::vector<std::pair<int,int>> B_N({{6,3}});
const std::vector<std::pair<int,int>> P2({{9,1}});
const std::vector<std::pair<int,int>> T_B({{10,7}});
const std::vector<std::pair<int,int>> Y_N_DOT ({{22,24}});
const std::vector<std::pair<int,int>> Y_N_DOT_DOT ({{46,5}});
const std::vector<std::pair<int,int>> Y_N({{51,27}});

//STRING 3
const std::vector<std::pair<int,int>> P3({{6,1}});
const std::vector<std::pair<int,int>> GAMMA_N({{7,11}});
const std::vector<std::pair<int,int>> P({{19,2}});
const std::vector<std::pair<int,int>> L_N({{21,1}});
const std::vector<std::pair<int,int>> Z_N_DOT ({{22,24}});
const std::vector<std::pair<int,int>> Z_N_DOT_DOT ({{46,5}});
const std::vector<std::pair<int,int>> Z_N({{51,27}});

// STRING 4
const std::vector<std::pair<int,int>> TAU_N({{6,22}});
const std::vector<std::pair<int,int>> DELTA_TAU_N({{28,5}});
const std::vector<std::pair<int,int>> E_N({{33,5}});
const std::vector<std::pair<int,int>> P4 ({{52,1}});
const std::vector<std::pair<int,int>> F_T ({{53,4}});
const std::vector<std::pair<int,int>> N_T({{60,11}});
const std::vector<std::pair<int,int>> N({{71,5}});
const std::vector<std::pair<int,int>> M({{76,2}});

// STRING 5
const std::vector<std::pair<int,int>> N_A({{6,11}});
const std::vector<std::pair<int,int>> TAU_C({{17,32}});
const std::vector<std::pair<int,int>> N_4({{50,5}});
const std::vector<std::pair<int,int>> TAU_GPS({{55,22}});
const std::vector<std::pair<int,int>> L_N({{77,1}});

// STRING 6, 8, 10, 12, 14
const std::vector<std::pair<int,int>> C_N({{6,1}});
const std::vector<std::pair<int,int>> M_N_A({{7,2}});
const std::vector<std::pair<int,int>> n_A({{9,5}});
const std::vector<std::pair<int,int>> TAU_N_A({{14,10}});
const std::vector<std::pair<int,int>> LAMBDA_N_A({{24,21}});
const std::vector<std::pair<int,int>> DELTA_I_N_A({{45,18}});
const std::vector<std::pair<int,int>> EPSILON_N_A({{63,15}});

//STRING 7, 9, 11, 13, 15
const std::vector<std::pair<int,int>> OMEGA_N_A({{6,16}});
const std::vector<std::pair<int,int>> T_LAMBDA_N_A({{22,21}});
const std::vector<std::pair<int,int>> DELTA_T_N_A({{43,22}});
const std::vector<std::pair<int,int>> DELTA_T_DOT_N_A({{65,7}});
const std::vector<std::pair<int,int>> H_N_A({{72,5}});
const std::vector<std::pair<int,int>> L_N({{77,1}});


#endif /* GNSS_SDR_GLONASS_L1_CA_H_ */
