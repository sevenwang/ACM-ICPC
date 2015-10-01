#include <string>
#include <vector>
std::string DelSubString(std::string strSrc, std::string strDel)
{
	std::vector<int> vecMask;
	vecMask.resize(strSrc.size(), 0);

	size_t i = 0;
	for (i=0; i<strSrc.size(); i++)
	{
		if (strSrc.substr(i, strDel.size()) == strDel)
		{
			for (size_t j=0; j<strDel.size(); j++)
			{
				vecMask[i + j] = 1;
			}
		}
	}
	std::string strRet;
	for (i=0; i<vecMask.size(); i++)
	{
		if (0 == vecMask[i])
		{
			strRet.append(1, strSrc[i]);
		}
	}
	return strRet;
}


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      return 0;
}
/*

*/
