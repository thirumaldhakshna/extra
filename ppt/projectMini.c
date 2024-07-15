#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct institute{
    char university[150];
    char school[150];
    int studetsCount;
}clg;

struct analysis{
    int totalStudents;
    int passedStudents;
    int pendingStudents;
    int raStudents;
    int others;
}alys;

struct studentsData{
    char name[20];
    int rollno;
    char dept[10];
    char result[12];
}data[];

void indexHTML();
void analysisData();

void main(){
    char school[200];
    int count;
    FILE *fp, *fp2;
    printf("Enter University: ");
    gets(clg.university);
    printf("Enter School: ");
    gets(clg.school);
    printf("Enter Count of Students: ");
    scanf("%d", &clg.studetsCount);

    printf("\n");
    data[clg.studetsCount];
    for (int i = 0; i < clg.studetsCount; i++){
        printf("Enter Stundet No. %d - Name: ", i + 1);
        scanf("%s", &data[i].name);
        printf("Enter %s\'s Roll No.: ", data[i].name);
        scanf("%d", &data[i].rollno);
        printf("Enter %s\'s Dept.: ", data[i].name);
        scanf("%s", &data[i].dept);
        printf("Enter %s\'s Result: ", data[i].name);
        scanf("%s", &data[i].result);
        printf("\n-------------------------\n");
    }
    analysisData();
    indexHTML();
    printf("Data\'s SuccessFully Stored in HTML file !");
}
int checkSTR(char str1[], char str2[]){
    int key;
    if(0 == (strcmp(str1, str2))){
        key = 1;
    }
    else{
        key = 0;
    }
    
    return key;
}
void analysisData(){
    alys.totalStudents = clg.studetsCount;
    for (int i = 0; i<clg.studetsCount; i++){
        if (1 == checkSTR("PASS", strupr(data[i].result))){
            alys.passedStudents += 1;
        }
        else if (1 == checkSTR("PENDING", strupr(data[i].result))){
            alys.pendingStudents += 1;
        }
        else if (1 == checkSTR("RA", strupr(data[i].result))){
            alys.raStudents += 1;
        }
        else{
            alys.others += 1;
        }
    }
}

void table(char name[20], int rollno, char dept[10], char result[12]){
    FILE *html;
    html = fopen("index.html", "a");
    fprintf(html, "<tr>\n");
    fprintf(html, "<td>%s</td>", strupr(name));
    ((rollno) == 0) ? fprintf(html, "<td>%s</td>", "---") : fprintf(html, "<td>#%d</td>", rollno);
    fprintf(html, "<td>%s</td>", strupr(dept));
    fprintf(html, "<td>%s</td>", strupr(result));
    fprintf(html, "</tr>\n");
    fclose(html);
}
void indexHTML(){
    FILE *html;
    html = fopen("index.html", "w");
    fprintf(html, "<!DOCTYPE html>\n<html>\n<heat>\n<style>\n");
    fprintf(html, "body{width: 100%%; font-family: sans-serif;  background-color: #f9f9f9; display: flex; justify-content: center;  align-items: center; flex-direction: column;}");
    fprintf(html, ".container{width: 60%%; border-radius: 5px; background-color:#fff; padding: 30px; box-shadow: 2px 2px 10px black; margin-block:30px;}");
    fprintf(html, "table, th, td{border: 1px solid lightgray; border-collapse: collapse; text-align: center;} th, td{padding: 10px;} table{width: 100%%;} td{font-family: Monospace; font-size: 18px;}");
    fprintf(html, "h2, h3{text-align: center;} h2{color: #0047AB;} h3{color: #DAA520;} h4{color: #4F7942} span{font-family: monospace; font-size: 18px;}");
    fprintf(html, "</style>\n</heat>\n");
    fprintf(html, "<div class=\"container\">\n");
    fprintf(html, "<h2>%s</h2>\n<h3>%s</h3>\n<p>Student Count: %d</p>\n", strupr(clg.university), strupr(clg.school), clg.studetsCount);
    fprintf(html, "<table>\n<tr>\n<th>Name</th>\n<th>Roll Number</th>\n<th>Depatment</th>\n<th>Result Status</th></tr>");
    fclose(html);
    
    for (int i = 0; i<clg.studetsCount; i++){
        table(data[i].name, data[i].rollno, data[i].dept, data[i].result);
    }

    // FILE *html;
    html = fopen("index.html", "a");
    fprintf(html, "</table>");
    fprintf(html, "<h4>Analysis</h4>\n<table>\n");
    fprintf(html, "<tr>\n<th>Total Students</th>\n<td>%d</td>\n</tr>\n", alys.totalStudents);
    fprintf(html, "<tr>\n<th>Passed Students</th>\n<td>%d</td>\n</tr>\n", alys.passedStudents);
    fprintf(html, "<tr>\n<th>Pending Students</th>\n<td>%d</td>\n</tr>\n", alys.pendingStudents);
    fprintf(html, "<tr>\n<th>RA Students</th>\n<td>%d</td>\n</tr>\n", alys.raStudents);
    fprintf(html, "<tr>\n<th>Others</th>\n<td>%d</td>\n</tr>\n", alys.others);
    fprintf(html, "</table>");

    fprintf(html, "</div>\n<span>developed by @ThirumalDhakshnamoorthy</span>\n</body>\n</html>");
    fclose(html);
}