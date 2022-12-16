#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "BIT_Math.h"
#include "STD_Types.h"
#include "System.h"

uint8 SYSTEM_u8Size = 1;
uint8 SYSTEM_u8Iter = 0;

void SYSTEM_VoidNoData()
{
	printf("====================================\n");
	printf("====================================\n");
	printf("the list is Empty no data to view !\n");
	printf("====================================\n");
	printf("====================================\n");
}





void SYSTEM_VoidAddNewStudent(tstrSrudentData* pastrSrudentDataCPY)
{
	uint8 u8IerLoc;

	

	printf("please enter student id        : ");
	scanf("%d", &pastrSrudentDataCPY[SYSTEM_u8Iter].as32IDLoc);
	fflush(stdin);
	for (u8IerLoc = 0; u8IerLoc < SYSTEM_u8Iter; u8IerLoc++)
	{
		if (pastrSrudentDataCPY[SYSTEM_u8Iter].as32IDLoc == pastrSrudentDataCPY[u8IerLoc].as32IDLoc)
		{
			printf("====================================\n");
			printf("====================================\n");
			printf("      the id is already exist      \n");
			printf("====================================\n");
			printf("====================================\n");
			return; 
		}
	}

	printf("please enter student Name        : ");
	pastrSrudentDataCPY[SYSTEM_u8Iter].pas32NAmeLoc = (uint8*)malloc(sizeof(uint8) * 20);
	fgets(pastrSrudentDataCPY[SYSTEM_u8Iter].pas32NAmeLoc, 20, stdin);

	printf("please enter student birth date  : ");
	pastrSrudentDataCPY[SYSTEM_u8Iter].pas32BirthDAteLoc = (uint8*)malloc(sizeof(uint8) * 20);
	fgets(pastrSrudentDataCPY[SYSTEM_u8Iter].pas32BirthDAteLoc, 20, stdin);

	printf("please enter student Address     : ");
	pastrSrudentDataCPY[SYSTEM_u8Iter].pas32AddressLoc = (uint8*)malloc(sizeof(uint8) * 20);
	fgets(pastrSrudentDataCPY[SYSTEM_u8Iter].pas32AddressLoc, 20, stdin);

	printf("please enter studen phone number : ");
	scanf("%d", &pastrSrudentDataCPY[SYSTEM_u8Iter].as32PhoneLoc);

	do {
		printf("please enter student score       : ");
		scanf("%d", &pastrSrudentDataCPY[SYSTEM_u8Iter].as32ScoreLoc);
	} while ((pastrSrudentDataCPY[SYSTEM_u8Iter].as32ScoreLoc > 100) || (pastrSrudentDataCPY[SYSTEM_u8Iter].as32ScoreLoc < 0));

	SYSTEM_u8Size++;
	SYSTEM_u8Iter++;

	

	printf("student ID  address         : %d\n", pastrSrudentDataCPY);
}


void SYSTEM_VoidPrintStudent(tstrSrudentData* pastrSrudentDataCPY)
{
	uint8 u8Ier1Loc;
	uint8 u8Ier2Loc;
	tstrSrudentData strSrudentDataTempLoc;

	if (SYSTEM_u8Iter == 0)
	{
		SYSTEM_VoidNoData();
	}
	else
	{
		for (u8Ier1Loc = 0; u8Ier1Loc < SYSTEM_u8Iter; u8Ier1Loc++)
		{
			for (u8Ier2Loc = 0; u8Ier2Loc < SYSTEM_u8Iter - 1; u8Ier2Loc++)
			{
				if (strcmp(pastrSrudentDataCPY[u8Ier1Loc].pas32NAmeLoc ,pastrSrudentDataCPY[u8Ier2Loc].pas32NAmeLoc)<0)
				{
					strSrudentDataTempLoc = pastrSrudentDataCPY[u8Ier2Loc];
					pastrSrudentDataCPY[u8Ier2Loc] = pastrSrudentDataCPY[u8Ier1Loc];
					pastrSrudentDataCPY[u8Ier1Loc] = strSrudentDataTempLoc;
				}
			}
		}

		for (u8Ier1Loc = 0; u8Ier1Loc < SYSTEM_u8Iter; u8Ier1Loc++)
		{
			printf("==============================================\n");
			
			printf("student ID           : %d\n", pastrSrudentDataCPY[u8Ier1Loc].as32IDLoc);
			printf("Student Name         : %s", pastrSrudentDataCPY[u8Ier1Loc].pas32NAmeLoc);
			printf("Student Birth Date   : %s", pastrSrudentDataCPY[u8Ier1Loc].pas32BirthDAteLoc);
			printf("Student Address      : %s", pastrSrudentDataCPY[u8Ier1Loc].pas32AddressLoc);
			printf("Student Phone number : %d\n", pastrSrudentDataCPY[u8Ier1Loc].as32PhoneLoc);
			printf("Student Score        : %d\n", pastrSrudentDataCPY[u8Ier1Loc].as32ScoreLoc);
			printf("==============================================\n");
		}
	}
}


void SYSTEM_VoidDeleteStudent(tstrSrudentData* pastrSrudentDataCPY)
{
	uint32 u32DeletLoc;
	uint8 u8Index;
	uint8 u8IerLoc;
	if (SYSTEM_u8Iter == 0)
	{
		SYSTEM_VoidNoData();
	}
	else
	{
		printf("================================================\n");
		printf("\nPlease enter id of student you want to delete : ");
		scanf("%d", &u32DeletLoc);
		for (u8IerLoc = 0; u8IerLoc < SYSTEM_u8Iter; u8IerLoc++)
		{
			if (u32DeletLoc == pastrSrudentDataCPY[u8IerLoc].as32IDLoc)
			{
				pastrSrudentDataCPY[u8IerLoc] = pastrSrudentDataCPY[u8IerLoc + 1];
				SYSTEM_u8Size--;
				SYSTEM_u8Iter--;
			}
		}
	}
}


void SYSTEM_VoidUpdateStudent(tstrSrudentData* pastrSrudentDataCPY)
{
	uint32 u32EditIdLoc;
	uint8 u8IerLoc;
	if (SYSTEM_u8Iter == 0)
	{
		SYSTEM_VoidNoData();
	}
	else
	{
		printf("==============================================\n");
		printf("\nplease enter id of student you need to edit : ");
		scanf("%d", &u32EditIdLoc);
		for (u8IerLoc = 0; u8IerLoc < SYSTEM_u8Iter; u8IerLoc++)
		{
			if (u32EditIdLoc == pastrSrudentDataCPY[u8IerLoc].as32IDLoc)
			{
				fflush(stdin);
				printf("Please Enter New Name              : ");
				fgets(pastrSrudentDataCPY[u8IerLoc].pas32NAmeLoc, 20, stdin);
				
				printf("Please Enter New Birth Date number : ");
				fgets(pastrSrudentDataCPY[u8IerLoc].pas32BirthDAteLoc, 20, stdin);
				
				printf("Please Enter New Address           : ");
				fgets(pastrSrudentDataCPY[u8IerLoc].pas32AddressLoc, 20, stdin);
				
							printf("Please Enter New Phone number      : ");
				scanf("%d", &pastrSrudentDataCPY[u8IerLoc].as32PhoneLoc);

				do {
					printf("Please Enter New Score             : ");
					scanf("%d", &pastrSrudentDataCPY[u8IerLoc].as32ScoreLoc);
				} while (pastrSrudentDataCPY[u8IerLoc].as32ScoreLoc > 100 || pastrSrudentDataCPY[u8IerLoc].as32ScoreLoc < 0);

				break;
			}
		}
	}

}



void SYSTEM_VoidRankStudent(tstrSrudentData* pastrSrudentDataCPY)
{
	uint8 u8Ier1Loc;
	uint8 u8Ier2Loc;
	uint8 au8IndexLoc[SYSTEM_u8Iter];
	tstrSrudentData strSrudentDataTempLoc;

	if (SYSTEM_u8Iter == 0)
	{
		SYSTEM_VoidNoData();
	}
	else
	{
		for (u8Ier1Loc = 0; u8Ier1Loc < SYSTEM_u8Iter; u8Ier1Loc++)
		{
			for (u8Ier2Loc = 0; u8Ier2Loc < SYSTEM_u8Iter-1; u8Ier2Loc++)
			{
				if (pastrSrudentDataCPY[u8Ier1Loc].as32ScoreLoc < pastrSrudentDataCPY[u8Ier2Loc].as32ScoreLoc)
				{
					strSrudentDataTempLoc = pastrSrudentDataCPY[u8Ier2Loc];
					pastrSrudentDataCPY[u8Ier2Loc] = pastrSrudentDataCPY[u8Ier1Loc];
					pastrSrudentDataCPY[u8Ier1Loc] = strSrudentDataTempLoc;
				}
			}
		}

		for (u8Ier1Loc = 0; u8Ier1Loc < SYSTEM_u8Iter; u8Ier1Loc++)
		{
			printf("==============================================\n");
			printf("student ID           : %d\n", pastrSrudentDataCPY[u8Ier1Loc].as32IDLoc);
			printf("Student Name         : %s", pastrSrudentDataCPY[u8Ier1Loc].pas32NAmeLoc);
			printf("Student Birth Date   : %s", pastrSrudentDataCPY[u8Ier1Loc].pas32BirthDAteLoc);
			printf("Student Address      : %s", pastrSrudentDataCPY[u8Ier1Loc].pas32AddressLoc);
			printf("Student Phone number : %d\n", pastrSrudentDataCPY[u8Ier1Loc].as32PhoneLoc);
			printf("Student Score        : %d\n", pastrSrudentDataCPY[u8Ier1Loc].as32ScoreLoc);
			printf("==============================================\n");
		}
	
	}
}




void SYSTEM_VoidStudentScore(tstrSrudentData* pastrSrudentDataCPY)
{
	uint8 u8IerLoc;
	if (pastrSrudentDataCPY[0].as32IDLoc == 0)
	{
		SYSTEM_VoidNoData(pastrSrudentDataCPY);
	}
	else
	{
		for (u8IerLoc = 0; u8IerLoc < SYSTEM_u8Iter; u8IerLoc++)
		{
			do {
				printf("Please Enter New Score of student [%d] : ", pastrSrudentDataCPY[u8IerLoc].as32IDLoc);
				scanf("%d", &pastrSrudentDataCPY[u8IerLoc].as32ScoreLoc);
				printf("\n");
			} while (pastrSrudentDataCPY[u8IerLoc].as32ScoreLoc > 100 || pastrSrudentDataCPY[u8IerLoc].as32ScoreLoc < 0);
		}
	}

}



