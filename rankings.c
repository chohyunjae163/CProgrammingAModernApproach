/*
// AUTHOR: HYUNJAECHO
// DATE: 2022-11-15
// PROGRAM: a variety of ranking methods
// https://rosettacode.org/wiki/Ranking_methods
*/

#include<stdio.h>
#include<string.h>

#define COMPETITOR_NUM 7
#define NAME_LEN 8
#define FUNCTION_CALLED() printf("\n%s calls\n",__func__)
#define FUNCTION_RETURNED() printf("%s returns\n",__func__)

/*
For each of the following ranking methods,
create a function/method/procedure/subroutine...
that applies the ranking method
to an ordered list of scores with scorers:
*/

void print_rank(int* scores, char names[][NAME_LEN], int rankings[COMPETITOR_NUM])
{
	for(int i = 0; i < COMPETITOR_NUM;++i)
	{
		printf("\t%d %s\t\t",scores[i], names[i]);
		printf("%d %s\n",rankings[i], names[i]);
	}
}

//Standard. (Ties share what would have been their first ordinal number).
void print_standard_ranking(int* scores, char names[][NAME_LEN])
{
	FUNCTION_CALLED();
	int prev_score = scores[0];
	int last_rank = 1;
	int equal = 0;
	int rankings[COMPETITOR_NUM] = { 1, 0 };
	for(int i = 1; i < COMPETITOR_NUM;++i)
	{
		int score_diff = (prev_score - scores[i]);
		int step = !!(score_diff);
		int rank = (last_rank + step);
		if(score_diff != 0)
		{
			rank += equal;
			equal = 0;
		}
		else
		{
			equal += 1;
		}
		rankings[i] = rank;
		prev_score = scores[i];
		last_rank = rank;
	}

	print_rank(scores,names,rankings);
	FUNCTION_RETURNED();
}
//Modified. (Ties share what would have been their last ordinal number).
void print_modified_ranking(int* scores, char names[][NAME_LEN])
{
	FUNCTION_CALLED();
	int prev_score = scores[COMPETITOR_NUM - 1];
	int last_rank = COMPETITOR_NUM;
	int equal = 0;
	int rankings[COMPETITOR_NUM] = { 1, 0 };
	rankings[COMPETITOR_NUM - 1] = COMPETITOR_NUM;
	for(int i = COMPETITOR_NUM - 2; i > 0;--i)
	{
		int score_diff = (prev_score - scores[i]);
		int step = !!(score_diff);
		int rank = (last_rank - step);
		if(score_diff != 0)
		{
			rank -= equal;
			equal = 0;
		}
		else
		{
			equal += 1;
		}
		rankings[i] = rank;
		prev_score = scores[i];
		last_rank = rank;
	}

	print_rank(scores,names,rankings);
	FUNCTION_RETURNED();
}
//Dense. (Ties share the next available integer).
void print_dense_ranking(int* scores, char names[][NAME_LEN])
{
	FUNCTION_CALLED();
	int prev_score = scores[0];
	int last_rank = 1;
	int rankings[COMPETITOR_NUM] = { 1, 0 };
	for(int i = 1; i < COMPETITOR_NUM;++i)
	{
		int score_diff = (prev_score - scores[i]);
		int step = !!(score_diff);
		int rank = (last_rank + step);
		rankings[i] = rank;
		prev_score = scores[i];
		last_rank = rank;
	}

	print_rank(scores,names,rankings);
	FUNCTION_RETURNED();
}
//Ordinal. ((Competitors take the next available integer. Ties are not treated otherwise).
void print_ordinal_ranking(int* scores, char names[][NAME_LEN])
{
	FUNCTION_CALLED();
	int prev_score = scores[0];
	int rankings[COMPETITOR_NUM] = { 1, 0 };
	for(int i = 1; i < COMPETITOR_NUM;++i)
	{
	    int current_score = scores[i];
		if(prev_score == current_score)
		{
			int j = 1;
			char curr[NAME_LEN];
			memcpy(curr,names[i],NAME_LEN);
			int swap_count = 0;
			//같은 점수의 이름들을  alphabetical order가 맞을때까지 스왑
			while (i - j > -1 && scores[i - j] == prev_score)
			{
				char* prev = names[i-j];
				int curr_index = 0;
				//alphabetical order로 이름 스왑하기
				while(*prev != '\0' || curr[curr_index] != '\0')
				{
					int diff = *prev - curr[curr_index];
                    ++prev;
					++curr_index;
					if(diff > 0)
					{
						//swap
						char temp[NAME_LEN];
						memcpy(temp,names[i-j],NAME_LEN);
                        memcpy(names[i-j],names[i - swap_count],NAME_LEN);
                        memcpy(names[i - swap_count],temp,NAME_LEN);
                        swap_count++;
                        break;
					}
					else if (diff < 0)
					{
						break;
					}

				}
				//모든 알파벳이 동일한데 현재 이름이 상위 랭크의 이름보다 길이가 짧을때 스왑
				if(*curr == '\0' && *prev != '\0')
				{
                    //swap
					char temp[NAME_LEN];
					memcpy(temp,names[i-j],NAME_LEN);
                    memcpy(names[i-j],names[i - swap_count],NAME_LEN);
                    memcpy(names[i - swap_count],temp,NAME_LEN);
                    swap_count++;
                    break;
				}
				++j;
			}
		}

		prev_score = current_score;
		rankings[i] = i + 1;
	}
	print_rank(scores,names,rankings);
	FUNCTION_RETURNED();
}
//Fractional. (Ties share the mean of what would have been their ordinal numbers).
void print_fractional_ranking(int* scores, char names[][NAME_LEN])
{
	FUNCTION_CALLED();
    float rankings[COMPETITOR_NUM];
    memset(rankings,0,COMPETITOR_NUM * sizeof(float));
    int next_index = 0 ;
    for(int i = 0; i < COMPETITOR_NUM;++i)
    {
        next_index = i + 1;
        if(scores[next_index] == scores[i])
        {
            while(scores[next_index] == scores[i])
            {
                ++next_index;
            }
            float average = 0.0f;
            for(int j = i; j < next_index;++j)
            {
                average += (j+1);
            }
            average /= (next_index - i);
            for(int j = i; j < next_index;++j)
            {
                rankings[j] = average;
            }
            i = next_index - 1;
        }
        else
        {
         rankings[i] = i + 1;
        }

    }
	for(int i = 0; i < COMPETITOR_NUM;++i)
	{
		printf("\t%d %s\t\t",scores[i], names[i]);
		printf("%.1f %s\n",rankings[i], names[i]);
	}

	FUNCTION_RETURNED();
}


int main()
{
	FILE* fptr = fopen("ranks.txt","r");
	if (fptr == NULL) {
        printf("no such file.");
    	return 0;
    }
	int scores[COMPETITOR_NUM] = { 0 };
	char buffer[COMPETITOR_NUM][NAME_LEN];
	int index = 0;
	while(fscanf(fptr,"%d %s", &scores[index], buffer[index]) == 2)
	{
		index++;
	}

	for(int i = 0; i < COMPETITOR_NUM;++i)
	{
		printf("%d ", scores[i]);
		printf("%s\n", buffer[i]);
	}


	print_standard_ranking(scores,buffer);
	print_modified_ranking(scores,buffer);
	print_dense_ranking(scores,buffer);
	print_ordinal_ranking(scores,buffer);
	print_fractional_ranking(scores,buffer);
	fclose(fptr);
	return 0;
}
