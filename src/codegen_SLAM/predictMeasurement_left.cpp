//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictMeasurement_left.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 14-Aug-2015 12:23:30
//

// Include Files
#include "rt_nonfinite.h"
#include "SLAM.h"
#include "predictMeasurement_left.h"
#include "predictMeasurement_stereo.h"
#include "SLAM_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// PREDICTMEASUREMENT Predict the measurement of a feature given in the left
// camera frame
//    Get the pixel coordinates where a feature given in the left camera
//    frame would be visible in both cameras
// Arguments    : const double fp_l[3]
//                double h_u_l[2]
// Return Type  : void
//
void predictMeasurement_left(const double fp_l[3], double h_u_l[2])
{
  double h_cin_l[3];
  int i;
  double radsq_l;
  double b;

  //  camera parameters for the left and right camera
  //  r_lr = cameraparams.r_lr;
  //  R_lr = cameraparams.R_lr;
  //  R_rl=R_lr';
  //  if fp_l(3) == 0
  //      ROS_ERROR('h_ci_l(3)==0')
  //  end
  //  if fp_r(3) == 0
  //      ROS_ERROR('h_ci_r(3)==0')
  //  end
  for (i = 0; i < 3; i++) {
    h_cin_l[i] = fp_l[i] / fp_l[2];
  }

  //  if any(isnan(h_cin_l))
  //      ROS_ERROR('h_cin_l')
  //      ROS_ERROR('h_ci_l(3) = %f', h_cin_l(3))
  //  end
  //  if any(isnan(h_cin_r))
  //      ROS_ERROR('h_cin_r')
  //      ROS_ERROR('h_ci_r(3) = %f', h_cin_r(3))
  //  end
  //  h_uin_l = h_cin_l(1:2);
  //  h_uin_r = h_cin_r(1:2);
  //  if any(isnan(h_uin_l))
  //      ROS_ERROR('h_uin_l')
  //  end
  //  if any(isnan(h_uin_r))
  //      ROS_ERROR('h_uin_r')
  //  end
  //  rad_l=sqrt(h_uin_l(1)^2+h_uin_l(2)^2);
  //  rad_r=sqrt(h_uin_r(1)^2+h_uin_r(2)^2);
  radsq_l = h_cin_l[0] * h_cin_l[0] + h_cin_l[1] * h_cin_l[1];
  b = ((1.0 + -0.409008681589769 * radsq_l) + 0.234049866705913 * (radsq_l *
        radsq_l)) + -0.0867772601866113 * rt_powd_snf(radsq_l, 4.0);
  for (i = 0; i < 3; i++) {
    h_cin_l[i] *= b;
  }

  //  if any(isnan(rad_l))
  //      ROS_ERROR('rad_l')
  //  end
  //  if any(isnan(rad_r))
  //      ROS_ERROR('rad_r')
  //  end
  //  if any(isnan(h_din_l))
  //      ROS_ERROR('h_din_l')
  //  end
  //  if any(isnan(h_din_r))
  //      ROS_ERROR('h_din_r')
  //  end
  h_u_l[0] = 156.807897369143 + 268.918969857515 * h_cin_l[0];
  h_u_l[1] = 113.687513761586 + 269.522862126881 * h_cin_l[1];

  //  if any(isnan(h_u_l))
  //      ROS_ERROR('h_di_l')
  //  end
  //  if any(isnan(h_u_r))
  //      ROS_ERROR('h_di_r')
  //  end
}

//
// File trailer for predictMeasurement_left.cpp
//
// [EOF]
//