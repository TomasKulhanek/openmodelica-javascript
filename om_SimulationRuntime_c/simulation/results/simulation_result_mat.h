/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THE BSD NEW LICENSE OR THE
 * GPL VERSION 3 LICENSE OR THE OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the OSMC (Open Source Modelica Consortium)
 * Public License (OSMC-PL) are obtained from OSMC, either from the above
 * address, from the URLs: http://www.openmodelica.org or
 * http://www.ida.liu.se/projects/OpenModelica, and in the OpenModelica
 * distribution. GNU version 3 is obtained from:
 * http://www.gnu.org/copyleft/gpl.html. The New BSD License is obtained from:
 * http://www.opensource.org/licenses/BSD-3-Clause.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, EXCEPT AS
 * EXPRESSLY SET FORTH IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE
 * CONDITIONS OF OSMC-PL.
 *
 */

/*
  Stores results into MAT-file version 4 in format of Dymosim's result file.

  Specifications of MAT-file ver4 are available from:
  http://www.mathworks.com/access/helpdesk/help/pdf_doc/matlab/matfile_format.pdf

  Specification of Dymosim's result file are available from (pages 213-214):
  http://www.inf.ethz.ch/personal/cellier/Lect/MMPS/Refs/Dymola5Manual.pdf
 */

#ifndef _SIMULATION_RESULT_MAT_H_
#define _SIMULATION_RESULT_MAT_H_

#include "simulation_result.h"
#include "simulation_data.h"

#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */

void mat4_init(simulation_result *self,DATA *data);
void mat4_emit(simulation_result *self,DATA *data);
void mat4_writeParameterData(simulation_result *self,DATA *data);
void mat4_free(simulation_result *self,DATA *data);

#ifdef __cplusplus
}
#endif /* cplusplus */

#endif /* _SIMULATION_RESULT_MAT_H_ */