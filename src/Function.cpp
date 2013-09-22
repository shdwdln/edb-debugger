
#include "Function.h"

//------------------------------------------------------------------------------
// Name: Function
//------------------------------------------------------------------------------
Function::Function() : entry_address_(0), end_address_(0), last_instruction_(0), reference_count_(0) {

}

//------------------------------------------------------------------------------
// Name: Function
//------------------------------------------------------------------------------
Function::Function(const Function &other) : entry_address_(other.entry_address_), end_address_(other.end_address_), last_instruction_(other.last_instruction_), reference_count_(other.reference_count_), blocks_(other.blocks_) {
}

//------------------------------------------------------------------------------
// Name: operator=
//------------------------------------------------------------------------------
Function &Function::operator=(const Function &rhs) {
	Function(rhs).swap(*this);
	return *this;
}

//------------------------------------------------------------------------------
// Name: swap
//------------------------------------------------------------------------------
void Function::swap(Function &other) {
	qSwap(entry_address_, other.entry_address_);
	qSwap(end_address_, other.end_address_);
	qSwap(last_instruction_, other.last_instruction_);
	qSwap(reference_count_, other.reference_count_);	
	qSwap(blocks_, other.blocks_);
}

//------------------------------------------------------------------------------
// Name: insert
//------------------------------------------------------------------------------
void Function::insert(const BasicBlock &bb) {
	blocks_[bb.first_address()] = bb;
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
edb::address_t Function::entry_address() const {
#if 0
	return entry_address_;
#else
	return front().first_address();
#endif
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
edb::address_t Function::end_address() const {
#if 0
	return end_address_;
#else
	return back().last_address() - 1;
#endif
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
edb::address_t Function::last_instruction() const {
	return last_instruction_;
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
int Function::reference_count() const {
	return reference_count_;
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::const_reference Function::back() const {
	Q_ASSERT(!empty());
	return *rbegin();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::const_reference Function::front() const {
	Q_ASSERT(!empty());
	return *begin();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::reference Function::back() {
	Q_ASSERT(!empty());
	return *rbegin();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::reference Function::front() {
	Q_ASSERT(!empty());
	return *begin();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::const_iterator Function::begin() const {
	return blocks_.begin();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::const_iterator Function::end() const {
	return blocks_.end();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::const_reverse_iterator Function::rbegin() const {
	return const_reverse_iterator(blocks_.end());
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::const_reverse_iterator Function::rend() const {
	return const_reverse_iterator(blocks_.begin());
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::iterator Function::begin() {
	return blocks_.begin();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::iterator Function::end() {
	return blocks_.end();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::reverse_iterator Function::rbegin() {
	return reverse_iterator(blocks_.end());
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::reverse_iterator Function::rend() {
	return reverse_iterator(blocks_.begin());
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
bool Function::empty() const {
	return blocks_.isEmpty();
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
Function::size_type Function::size() const {
	return blocks_.size();
}