long long calculateHours(int* piles, int pilesSize, int speed)
{
    long long hours = 0;

    for(int i = 0; i < pilesSize; i++)
    {
        hours += (piles[i] + speed - 1) / speed;
    }

    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h)
{
    int left = 1;
    int right = piles[0];

    for(int i = 1; i < pilesSize; i++)
    {
        if(piles[i] > right)
        {
            right = piles[i];
        }
    }

    while(left < right)
    {
        int mid = left + (right - left) / 2;

        if(calculateHours(piles, pilesSize, mid) <= h)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}
