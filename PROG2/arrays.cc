double getPositiveAverage(double myArray[], int numItems)
{
    if (numItems <= 0) return 0;
    double sum = 0;
    for (int i = 0; i < numItems; i++)
    {
        sum += myArray[i];
    }
    return sum / numItems;
}

int countRangeValues(double myArray[], int numItems, double toCount)
{
    int count = 0;
    double lowerBound = toCount - 0.5;
    double upperBound = toCount + 0.5;
    for (int i = 0; i < numItems; i++)
    {
        if (myArray[i] >= lowerBound && myArray[i] < upperBound) count++;
    }
    return count;
}

double getMaxAbsolute(double myArray[], int numItems)
{
    double max = 0;
    double maxAbsolute = 0;
    for (int i = 0; i < numItems; i++)
    {
        if (myArray[i] < 0)
        {
            if (-myArray[i] > maxAbsolute)
            {
                max = myArray[i];
                maxAbsolute = -max;
            }
        }
        else
        {
            if (myArray[i] >= maxAbsolute)
            {
                max = maxAbsolute = myArray[i];
            }
        }
    }
    return max;
}

int countInverses(int myArray[], int numItems)
{
    int pairs = 0;
    for (int i = 0; i < numItems; i++)
    {
        for (int j = i + 1; j < numItems; j++)
        {
            if (myArray[i] != 0 && myArray[j] != 0 && myArray[i] + myArray[j] == 0)
            {
                pairs++;
                myArray[i] = 0;
                myArray[j] = 0;
            }
        }
    }
    return pairs;
}

int getMaxCount(double myArray[], int numItems)
{
    double maxValue = getMaxAbsolute(myArray, numItems);
    return countRangeValues(myArray, numItems, maxValue);
}