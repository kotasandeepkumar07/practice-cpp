// CObject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"
#include "afxcoll.h"
#include "afx.h"


/*
class CAge : public CObject
{
    DECLARE_SERIAL( CAge )

private:
    int   m_years;

public:
    CAge() { m_years = 0; }

    CAge(int age) { m_years = age; }

    CAge(const CAge& a) { m_years = a.m_years; } // Copy constructor

    void Serialize(CArchive& ar);
    void AssertValid() const;

    const CAge& operator=(const CAge& a)
    {
        m_years = a.m_years; return *this;
    }

    BOOL operator==(CAge a)
    {
        return m_years == a.m_years;
    }


#ifdef _DEBUG
    void Dump(CDumpContext& dc) const ;
    
#endif
};


void CAge::Dump(CDumpContext &dc) const
{
   CObject::Dump(dc);
   dc << _T("Age = ") << m_years;
}


void main(int argc, char* argv[])
{
	
}
*/



class Serializable
{
public:
    Serializable(){}
    virtual ~Serializable(){}

    virtual void serialize(ostream& stream) = 0;
    virtual void deserialize(istream& stream) = 0;
};



struct PersonInfo : public Serializable // Yes! It's possible
{
    unsigned int age_;
    enum { undef, man, woman } sex_;

    virtual void serialize(ostream& stream)
    {
        // Serialization code
        stream << age_  << sex_;
    }

    virtual void deserialize(istream& stream)
    {
        // Deserialization code
       // stream >> age_  >> sex_;
    }
};


void main()
{
	PersonInfo obj;
	obj.serialize(ostream& p);


}