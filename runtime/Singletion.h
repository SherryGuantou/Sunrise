#pragma once

#define SINGLETION_CLASS(CLASS) \
public: \
	static CLASS* Get() { \
		static CLASS t; \
		return &t; \
	} \
private: \
	CLASS() = default; \
	~CLASS() = default; \
	CLASS(const CLASS&) = delete; \
	CLASS& operator=(const CLASS&) = delete;

#define SINGLETION_CLASS_WITH_INIT(CLASS) \
public: \
	static CLASS* Get() { \
		static CLASS t; \
		return &t; \
	} \
private: \
	CLASS() {Init(); }; \
	~CLASS() = default; \
	CLASS(const CLASS&) = delete; \
	CLASS& operator=(const CLASS&) = delete;

#define GET(CLASS) CLASS::Get()->