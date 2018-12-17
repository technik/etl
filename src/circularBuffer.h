////////////////////////////////////////////////////////////////////////////////
// BBDuino Library
//		Author: Carmelo J. Fdez-Ag�era Tortosa
//
//		Date:	2013/08/03
////////////////////////////////////////////////////////////////////////////////
// Circular buffer

#pragma once

#include <new.h>

#include <cstdint>
#include <cstddef>

template<class T_>
class CircularBuffer
{
public:
	CircularBuffer(size_t _bufferSize);
	~CircularBuffer();

	T_		read	();
	bool	write	(const T_& _x);
	bool	empty	() const; // Check this before you try to read data
	bool	full	() const; // Check this before you try to write data

	void	clear	();

private:
	T_*				mBuffer;
	size_t			mRead;
	size_t			mWrite;
	const size_t	mSize;
};

//---------------------------------------------------------------------------------------------------------------
// Inline implementation
//---------------------------------------------------------------------------------------------------------------
template<class T_>
CircularBuffer<T_>::CircularBuffer(size_t _bufferSize)
	:mRead(0)
	,mWrite(0)
	,mSize(_bufferSize)
{
	// Allocating the buffer as an array of bytes prevents constructor calling
	mBuffer = reinterpret_cast<T_*>(new std::uint8_t[mSize*sizeof(T_)]);
}

//---------------------------------------------------------------------------------------------------------------
template<class T_>
CircularBuffer<T_>::~CircularBuffer()
{
	clear();
	delete[] reinterpret_cast<std::uint8_t*>(mBuffer);
}

//---------------------------------------------------------------------------------------------------------------
template<class T_>
T_ CircularBuffer<T_>::read()
{
	// Buffer is assumed not to be empty
	T_ data = mBuffer[mRead]; // Store data
	mBuffer[mRead].~T_(); // Remove old data from the buffer
	// Displace read pointer
	++mRead;
	mRead%=mSize;
	return data; // Return data
}

//---------------------------------------------------------------------------------------------------------------
template<class T_>
bool CircularBuffer<T_>::write(const T_& _data)
{
	size_t writeNext = (mWrite+1)%mSize;
	if(writeNext != mRead) // Can write
	{
		mBuffer[mWrite] = _data;
		//new(&mBuffer[mWrite]) T_(_data); // Copy data into the buffer
		mWrite = writeNext; // Update write pointer
		return true;
	}
	else
		return false;
}

//---------------------------------------------------------------------------------------------------------------
template<class T_>
bool CircularBuffer<T_>::empty() const
{
	return mRead == mWrite;
}

//---------------------------------------------------------------------------------------------------------------
template<class T_>
bool CircularBuffer<T_>::full() const
{
	size_t writeNext = (mWrite+1)%mSize;
	return mRead == writeNext;
}

//---------------------------------------------------------------------------------------------------------------
template<class T_>
void CircularBuffer<T_>::clear()
{
	while(!empty())
		read();
}
