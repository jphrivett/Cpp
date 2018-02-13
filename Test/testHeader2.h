class Storage // full definition of Storage class
{
private:
	int m_nValue;
	double m_dValue;
public:
	Storage(int nValue, double dValue)
	{
		m_nValue = nValue;
		m_dValue = dValue;
	}

	// Make the Display::displayItem member function a friend of the Storage class (requires seeing the full declaration of class Display, as above)
	friend void Display::displayItem(Storage& storage);
};
