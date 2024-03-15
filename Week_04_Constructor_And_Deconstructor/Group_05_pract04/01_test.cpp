//#include <iostream>
//#include <fstream>
//
//#pragma warning(disable : 4996)
//
//namespace Constants
//{
//	constexpr size_t MAX_SIZE_NAME = 20;
//	constexpr size_t MAX_SIZE_TASK = 128;
//	constexpr size_t MAX_SIZE_PROBLEMS = 10;
//}
//
//class Problem
//{
//
//private:
//	char name[Constants::MAX_SIZE_NAME];
//	char task[Constants::MAX_SIZE_TASK];
//	int points = 0;
//
//public:
//	Problem() : points(0)
//	{
//		name[0] = '\0';
//		task[0] = '\0';
//	}
//
//	Problem(const char* name, const char* task, int points)
//	{
//		std::strcpy(this->name, name);
//		std::strcpy(this->task, task);
//		this->points = points;
//	}
//
//	const char* getName() const
//	{
//		return this->name;
//	}
//	
//	const char* getTask() const
//	{
//		return this->task;
//	}
//
//	int getPoints() const
//	{
//		return this->points;
//	}
//
//	void setName(const char* name)
//	{
//		std::strcpy(this->name, name);
//	}
//
//	void setTask()
//	{
//		std::strcpy(this->task, task);
//	}
//
//	void setPoints(int points)
//	{
//		this->points = points;
//	}
//
//};
//
//class Test
//{
//
//private:
//	Problem problems[Constants::MAX_SIZE_PROBLEMS];
//	int pointsCriteria;
//	size_t currProblemsSize;
//
//public:
//	Test() : pointsCriteria(0), currProblemsSize(0) {}
//
//	Test(const Problem* problems, int pointsCriteria, size_t currProblemsSize)
//	{
//		for (int i = 0; i < currProblemsSize; i++)
//		{
//			this->problems[i] = problems[i];
//		}
//
//		this->pointsCriteria = pointsCriteria;
//		this->currProblemsSize = currProblemsSize;
//	}
//
//	Problem getProblem(int index) const
//	{
//		return this->problems[index];
//	}
//
//	int getPointsCriteria() const
//	{
//		return this->pointsCriteria;
//	}
//
//	int getCurrProblemsSize() const
//	{
//		return this->currProblemsSize;
//	}
//
//	void setProblem(const Problem& problem, int index)
//	{
//		this->problems[index] = problem;
//	}
//
//	void setPointsCriteria(int pointsCriteria)
//	{
//		this->pointsCriteria = pointsCriteria;
//	}
//
//	void setCurrProblemsSize(size_t size)
//	{
//		this->currProblemsSize = size;
//	}
//};
//
//int maxPoints(const Test& test)
//{
//	int points = 0;
//	for (int i = 0; i < test.getCurrProblemsSize(); i++)
//	{
//		points += test.getProblem(i).getPoints();
//	}
//
//	return points;
//}
//
//void printTasks(const Test& test)
//{
//	for (int i = 0; i < test.getCurrProblemsSize(); i++)
//	{
//		std::cout << test.getProblem(i).getTask() << " " << std::endl;
//	}
//}
//
//void saveToFileBinary(const Test& test, const char* fileName)
//{
//	std::ofstream ofs(fileName, std::ios::binary);
//	ofs.write((const char*)&test, sizeof(test));
//	ofs.close();
//}
//
//void readFromFileBinary(Test& test, const char* fileName)
//{
//	std::ifstream ifs(fileName, std::ios::binary);
//	ifs.read((char*)&test, sizeof(test));
//	ifs.close();
//}
//
//int main()
//{
//	Test test;
//	Problem problem = { "name", "text", 10 };
//	test.setProblem(problem, 0);
//	test.setPointsCriteria(10);
//	test.setCurrProblemsSize(1);
//
//	std::cout << test.getProblem(0).getName() << std::endl;
//	std::cout << test.getProblem(0).getTask() << std::endl;
//	std::cout << test.getProblem(0).getPoints() << std::endl;
//
//	std::cout << maxPoints(test) << std::endl;
//	printTasks(test);
//
//	saveToFileBinary(test, "text.txt");
//	readFromFileBinary(test, "text.txt");
//
//	return 0;
//}