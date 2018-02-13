class Storage;

class Display
{
private:
	bool m_displayIntFirst;

public:
	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

	void displayItem(Storage &storage); // forward declaration above needed for this declaration line
};
