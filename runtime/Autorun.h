#pragma once

#include<functional>

template<class Func>
class AutoRun {
public:
	AutoRun(const std::function<Func> tFunc) {
		tFunc();
	}
public:
	AutoRun() = delete;
	AutoRun(const AutoRun&) = delete;
	AutoRun& operator=(const AutoRun&) = delete;
	~AutoRun() = default;
};
