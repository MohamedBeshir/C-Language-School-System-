/**************************************/
/* Description : system lib           */
/* Author      : Mohamed Beshir       */
/* Version     : 0.2v                 */
/* Date        : 25 Nov 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef  SYSTEM_H
#define  SYSTEM_H


typedef struct {

	uint32  as32IDLoc;
	uint8*  pas32NAmeLoc;
	uint8*  pas32BirthDAteLoc;
	uint8*  pas32AddressLoc;
	uint32  as32PhoneLoc;
	uint32  as32ScoreLoc;

}tstrSrudentData;



#define NULL_PTR (void *) 0


void SYSTEM_VoidNoData();
void SYSTEM_VoidAddNewStudent(tstrSrudentData* pastrSrudentDataCPY);
void SYSTEM_VoidPrintStudent(tstrSrudentData* pastrSrudentDataCPY);
void SYSTEM_VoidDeleteStudent(tstrSrudentData* pastrSrudentDataCPY);
void SYSTEM_VoidUpdateStudent(tstrSrudentData* pastrSrudentDataCPY);
void SYSTEM_VoidRankStudent(tstrSrudentData* pastrSrudentDataCPY);
void SYSTEM_VoidStudentScore(tstrSrudentData* pastrSrudentDataCPY);



#endif



