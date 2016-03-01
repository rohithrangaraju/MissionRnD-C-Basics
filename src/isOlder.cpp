/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isValidate(char *dob);
int isOlder(char *dob1, char *dob2) {
	int i, x = 0, y = 0, z,n;
	z = isValidate(dob1);
	n= isValidate(dob2);
	if (z == 1&&n==1){
		for (i = 6; i <= 9; i++){
			x += (int)dob1[i];
			x *= 10;
			y += (int)dob2[i];
			y *= 10;
		}
		if ((x - y)<0)
			return 1;
		else if ((x - y) > 0)
			return 2;
		else{
			x = 0; y = 0;
			for (i = 3; i <= 4; i++){
				x +=(int) dob1[i];
				x *= 10;
				y += (int)dob2[i];
				y *= 10;
			}
			if ((x - y)<0)
				return 1;
			else if ((x - y) > 0)
				return 2;
			else{
				x = 0; y = 0;
				for (i = 0; i < 2; i++){
					x += (int)dob1[i];
					x *= 10;
					y += (int)dob2[i];
					y *= 10;
				}
				if ((x - y)<0)
					return 1;
				else if ((x - y) > 0) return 2;

				else
					return 0;
			}

		}
	}
	else
		return -1;
}
int isValidate(char *dob){
	
	if (dob[2] != '-'&&dob[5] != '-')
		return -1;
	else{
		int d, m, y=0,i;
		d= (dob[0] - '0') * 10 + dob[1] - '0';
		m = (dob[3] - '0') * 10 + dob[4] - '0';
		y=(dob[6] - '0') * 1000 + (dob[7] - '0') * 100 + (dob[8] - '0') * 10 + (dob[9] - '0');
		
		if (y<=9999)
		{
			if (m <= 12){
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
					if (d <= 31)
						return 1;
					else
						return -1;
				}
				if (m == 2){
					if (y % 4 == 0){
						if (d <= 29)
							return 1;
						else
							return -1;
					}
					else{
						if (d <= 28)
							return 1;
						else
							return -1;
					}
				}
				if (m == 4 || m == 6 || m == 9 || m == 11){

					if (d <= 30)
						return 1;
					else
						return -1;
				}
			}
			else
				return -1;


		}
		else
			return -1;
	}

}
