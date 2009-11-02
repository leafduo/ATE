inline bool Formula::empty() const
{
    return formula.empty();
}

/*inline bool Formula::isRPN() const
{
    return !RPN.empty();
}*/

static inline bool Forluma::assignment()
{
    if (var <= maxVar) {
        ++var;
        return true;
    } else
        return false;
}

istream& operator>>(istream& in, Formula& f)
{
    string str;
    in >> str;
    f.formula = str;
    f.convertRPN();
    return in;
}

ostream& operator<<(ostream& out, const Formula& f)
{
    out << f.formula;
    return out;
}
