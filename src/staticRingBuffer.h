//-------------------------------------------------------------
// Copyright 2021 Carmelo J Fdez-Aguera
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#pragma once
#include <cstddef>
#include <array>

namespace etl
{
	template<class T, size_t capacity_>
	class FixedRingBuffer
	{
	public:
		static_assert(capacity_ > 0);

		bool empty() const { return writePos == readPos; }
		bool full() const { return writePos - readPos == capacity_; }
		constexpr size_t capacity() const { return capacity_; }
		size_t size() const { return writePos-readPos; }

		T& operator[](size_t i) { return buffer[(i+readPos)%capacity_]; }
		const T& operator[](size_t i) const { return buffer[(i+readPos)%capacity_]; }

		// Returns whether the element was successfully added to the buffer
		bool push_back(const T& x)
		{
			if(full()) return false;

			buffer[writePos%capacity_] = x;
			++writePos;
			return true;
		}

		T& back()
		{
			return buffer[(writePos-1)%capacity_];
		}

		const T& back() const
		{
			return buffer[(writePos-1)%capacity_];
		}

		T& front()
		{
			return buffer[readPos%capacity_];
		}

		const T& front() const
		{
			return buffer[readPos%capacity_];
		}

		void pop_front()
		{
			++readPos;
		}

		void clear()
		{
			readPos = writePos;
		}

	private:
		size_t writePos {};
		size_t readPos {};
		std::array<T,capacity_> buffer;
	};
}