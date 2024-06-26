#include <stdio.h>
#include <stdlib.h>

typedef struct {      // 학생 정보를 담는 구조체 정의
  char name[20];      // 이름 (최대 20글자)
  int id;             // 학번
  int scores[2];      // 2과목 성적
} Student;

int main(void) {                        // 3명의 학생 정보를 담을 배열 선언 및 초기화
  Student students[3] = {
    {"김철수", 20241111, {90, 85}},
    {"이영희", 20242222, {85, 92}},
    {"박지영", 20243333, {78, 83}},
  };

  FILE *fp = fopen("sj.txt", "w");      // 학생 정보를 sj.txt 파일에 저장
  if (fp == NULL) {
    printf("파일 열기 실패\n");
    return 1;
  }

  for (int i = 0; i < 3; i++) {         // 학생 정보 배열을 파일에 저장
    fprintf(fp, "%s %d %d %d\n", students[i].name, students[i].id, students[i].scores[0], students[i].scores[1]);
  }

  fclose(fp);
  printf("학생 정보 저장 완료\n");

  return 0;
}
