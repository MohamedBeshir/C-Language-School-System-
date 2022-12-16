#include<stdio.h>
#include<stdlib.h>

#include "BIT_Math.h"
#include "STD_Types.h"
#include "System.h"

extern uint8 SYSTEM_u8Size;
/*int** ppi;
ppi = malloc(sizeof(int*) * 3);
ppi[0] = malloc(sizeof(int) * 3);
ppi[1] = malloc(sizeof(int) * 2);
ppi[2] = malloc(sizeof(int) * 4);*/

void main()
{
	
	tstrSrudentData* pastrSrudentData=(tstrSrudentData*)malloc(sizeof(tstrSrudentData));
	uint32 u8RunLoc = 1;


	while (u8RunLoc != 7)
	{
		printf("-------------ITI school-------------\n");
		printf("------------------------------------\n");
		printf("choose on of the following operation\n");
		printf("To add a new student       enter [1]\n");
		printf("To view all students       enter [2]\n");
		printf("To delete a student        enter [3]\n");
		printf("To update a student        enter [4]\n");
		printf("To rank all students       enter [5]\n");
		printf("To edit student score      enter [6]\n");
		printf("To exit the school app     enter [7]\n");
		printf("------------------------------------\n");
		printf("----> please entered desierd option : ");

		scanf("%d", &u8RunLoc);

		if (u8RunLoc == 1)
		{
			pastrSrudentData = (tstrSrudentData*)realloc(pastrSrudentData, (sizeof(tstrSrudentData) * (SYSTEM_u8Size)));
			SYSTEM_VoidAddNewStudent(pastrSrudentData);
		}
		else if (u8RunLoc == 2)
		{
			SYSTEM_VoidPrintStudent(pastrSrudentData);
		}
		else if (u8RunLoc == 3)
		{
			SYSTEM_VoidDeleteStudent(pastrSrudentData);

		}
		else if (u8RunLoc == 4)
		{
			SYSTEM_VoidUpdateStudent(pastrSrudentData);
		}
		else if (u8RunLoc == 5)
		{
			SYSTEM_VoidRankStudent(pastrSrudentData);
		}
		else if (u8RunLoc == 6)
		{
			SYSTEM_VoidStudentScore(pastrSrudentData);
		}
		else if (u8RunLoc > 7)
		{
			printf("you enterd invallid data please choose option between [1] to [7]\n");
		}

	}

}