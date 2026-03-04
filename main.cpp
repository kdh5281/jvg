#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct student {

	std::string name;

	int kor = 0;
	int eng = 0;

};

//최대값//
void maxscore(const std::vector<student>& stu) {
	int maxkor = 0;
	int maxeng = 0;

	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].kor > maxkor)
			maxkor = stu[i].kor;
		if (stu[i].eng > maxeng)
			maxeng = stu[i].eng;
	}
	std::cout << "\n[최대 점수]\n";
	std::cout << "국어 최고점 : " << maxkor << "점\n";
	std::cout << "영어 최고점 : " << maxeng << "점\n";
}

//전체 리스트 출력 함수//
void studentlist(const std::vector<student>& stu) {  //const : 읽기 전용 함수임을 표시 , 함수 안에서 실수로 값을 바꾸는 것을 컴파일 단계에서 차단
	std::cout << "\n\n[전체 5r리스트]" << std::endl;
	for (int i = 0; i < stu.size(); i++) {
		std::cout << i << "번째 학생";
		std::cout << stu[i].name << "\t";
		std::cout << "국어" << stu[i].kor << "점\t";
		std::cout << "영어" << stu[i].eng << "점\n";
	}
}

	void avrscore(const std::vector<student>& stu) {
		double kor_sum = 0; //double = 평균 계산 시 소수점까지 정확히 계산
		double eng_sum = 0;

		for (int i = 0; i < stu.size(); i++) {
			kor_sum += stu[i].kor; // kor_sum = kor_sum + stu[i].kor; 와 같은 식
			eng_sum += stu[i].eng;
		}

			double kor_avg = kor_sum / stu.size(); //총합 ÷ 학생 수
			double eng_avg = eng_sum / stu.size();
			std::cout << "\n[평균 점수]\n" << std::endl;
			std::cout << "국어 평균값 : " << kor_avg << std::endl;
			std::cout << "영어 평균값 : " << eng_avg << std::endl;	
}
	int main() {

		std::vector<student> stu(5);
		for (int i = 0; i < 5; i++) {

			std::cout << "\n\n" << i << "번째 학생 정보 입력" << std::endl;
			std::cout << "이름: ";	
			std::cin >> stu[i].name;

			std::cout << "국어성적: ";
			std::cin >> stu[i].kor;

			std::cout << "영어성적: ";
			std::cin >> stu[i].eng;

			std::cout << stu[i].name << "\t" << "국어" << stu[i].kor << "점\t" << "영어" << stu[i].eng << "점\t";
		}
		studentlist(stu);
		maxscore(stu);
		avrscore(stu);

		std::ofstream fout("C:\\Users\\jvg12\\Desktop\\학생 성적.txt");

		if (!fout) {
			std::cerr << "파일을 열 수 없습니다" << std::endl;
			return 1;
		} //파일 열기 실패 체크

		for (int i = 0; i < stu.size(); i++) {
			fout << stu[i].name << " " << stu[i].kor << " " << stu[i].eng << std::endl;
		}

		fout.close();

		return 0;
	}

	