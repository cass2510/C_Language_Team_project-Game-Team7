#include <stdio.h>
#include <stdlib.h>

typedef struct {      // 학생 정보를 담는 구조체 정의
  char name[20];      // 이름 (최대 20글자)
  int id;             // 학번
  int scores[2];      // 2과목 성적
} Student;

int main(void) {                         // sj.txt 파일에서 값을 읽어 과목 평균 및 개인별 평균을 구해서 화면에 출력
  FILE *fp = fopen("sj.txt", "r");
  if (fp == NULL) {
    printf("파일 열기 실패\n");
    return 1;
  }

  int score1_sum = 0, score2_sum = 0;
  float subject_avg[2] = {0.0};
  float student_avg[3] = {0.0};


  for (int i = 0; i < 3; i++) {          // 파일에서 학생 정보 읽고 평균 계산
    char name[20];
    int id, score1, score2;
    fscanf(fp, "%s %d %d %d", name, &id, &score1, &score2);

    score1_sum += score1;
    score2_sum += score2;

    student_avg[i] = (float)(score1 + score2) / 2;
  }

  subject_avg[0] = (float)score1_sum / 3;
  subject_avg[1] = (float)score2_sum / 3;

  fclose(fp);

  printf("과목 평균:\n");                       // 평균 출력
  printf("과목1: %.2f\n", subject_avg[0]);
  printf("과목2: %.2f\n", subject_avg[1]);

  printf("\n개인별 평균:\n");
  for (int i = 0; i < 3; i++) {
    printf("학생 %d: %.2f\n", i + 1, student_avg[i]);
  }

  return 0;
}
