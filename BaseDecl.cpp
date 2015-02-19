#include "BaseDecl.h"

BaseDecl::BaseDecl(Symbol* ident, int size, bool isFloat) 
    : _ident(ident), _size(size), _isFloat(isFloat)
{

}

string BaseDecl::GetName()
{
    return _ident->GetIdentifier();
}
