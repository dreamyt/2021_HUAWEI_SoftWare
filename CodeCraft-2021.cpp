#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class Server{
private:
    std::string s_type;
    int mem_A; // mem and cpu are the available amounts.
    int mem_B;
    int cpu_A;
    int cpu_B;
    int server_cost;
    int power_cost;
    /*Price is not necessarily used here.*/
    //int price;
    //int day_cost;
public:
    Server(std::string s, int m_A, int m_B, int c_A, int c_B, int s_c, int p_c): s_type(s), mem_A(m_A), mem_B(m_B), cpu_A(c_A), cpu_B(c_B), server_cost(s_c), power_cost(p_c){};
};

class vm
{
private:
	int cpu;
	int mem;
	int node;
public:
	vm(int c, int m, int n): cpu(c), mem(m), node(n){};

};

class command
{
private:
    int command_type;
    std::string vm_type;
    int vm_id;
public:
    command(int c, std::string v, int id): command_type(c), vm_type(v), vm_id(id){};
};

std::vector<Server> s;//vector containing information of N available servers
std::unordered_map<std::string, vm> v;//map between the name of the vm and the vm information

std::vector<std::vector<command> > commands;//a vector of vectors consisting of every day commands

std::unordered_map<int, Server> purchase_infos;//map between purchased server ID and server information

std::vector<std::vector<int> > totalResources;//total resources needed every day

std::unordered_map<int, std::string> id_to_type;//map between vm ID and vm type name

std::unordered_map<int, int> vm_to_server;//map between vm ID and server ID

// generate server information
void generateServer(std::string &serverType, std::string &cpuCores, std::string &memorySize,
    std::string &serverCost, std::string &powerCost)
{
    std::string _serverType = "";
    for (int i = 1; i < serverType.size() - 1; ++i)
	{
        _serverType += serverType[i];
    }

    int _cpuCores = 0, _memorySize = 0, _serverCost = 0, _powerCost = 0;
    for (int i = 0; i < cpuCores.size() - 1; ++i)
	{
        _cpuCores = 10 * _cpuCores + cpuCores[i] - '0';
    }

    for (int i = 0; i < memorySize.size() - 1; ++i)
	{
        _memorySize = 10 * _memorySize + memorySize[i] - '0';
    }

    for (int i = 0; i < serverCost.size() - 1; ++i)
	{
        _serverCost = 10 * _serverCost + serverCost[i] - '0';
    }

    for (int i = 0; i < powerCost.size() - 1; ++i)
	{
        _powerCost = 10 * _powerCost + powerCost[i] - '0';
    }

	Server tmpInfo(_serverType, _memorySize / 2, _memorySize / 2,
			_cpuCores / 2, _cpuCores / 2, _serverCost, _powerCost);
	s.emplace_back(tmpInfo);
}

// generate virtual machine information
void generateVm(std::string &vmType, std::string &cpuCores, std::string &memorySize, std::string &isDouble)
{
	std::string _vmType = "";
	// (xxxxxx,
	for (int i = 1; i < vmType.size() - 1; ++i)//size()-1,不读逗号。从1开始，不读(
	{
		_vmType += vmType[i];
	}

	int _cpuCores = 0, _memorySize = 0, _isDouble = 0;

	for (int i = 0; i < cpuCores.size() - 1; ++i)
	{
		_cpuCores = 10 * _cpuCores + cpuCores[i] - '0';
	}

	for (int i = 0; i < memorySize.size() - 1; ++i)
	{
		_memorySize = 10 * _memorySize + memorySize[i] - '0';
	}

	_isDouble = isDouble[0] - '0';
	v.insert({_vmType, vm(_cpuCores, _memorySize, _isDouble)});
}

// generate command information
void generateCommand(int day, std::string &commandType, std::string &vmType, std::string &vmId)
{
	int _commandType = 0, _vmId = 0;
	std::string _vmType = "";
	if (commandType[1] == 'a')
		_commandType = 1;
	else
		_commandType = 0;

	if (vmType.size())
		for (int i = 0; i < vmType.size() - 1; ++i)
		{
			_vmType += vmType[i];
		}

	for (int i = 0; i < vmId.size() - 1; ++i)
	{
		_vmId = 10 * _vmId + vmId[i] - '0';
	}
	// 添加虚拟机Id 与 Type哈希表
	if (_commandType)
		id_to_type[_vmId] = _vmType;
	commands[day].emplace_back(_commandType, _vmType, _vmId);
}
int main()

{

	// TODO:read standard input

	// TODO:process

	// TODO:write standard output

	// TODO:fflush(stdout);

	return 0;

}
