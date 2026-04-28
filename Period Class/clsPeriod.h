#pragma once
#include <iostream>
#include "clsDate.h"

class clsPeriod
{
public:
    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;
    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After)
            return false;
        else
            return true;
    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
    }

    int PeriodLengthInDays(bool IncludeEndDate = false)
    {
        return PeriodLengthInDays(*this, IncludeEndDate);
    }

    static clsDate::enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (clsDate::IsDate1BeforeDate2(Date1, Date2))
            return clsDate::enDateCompare::Before;

        if (clsDate::IsDate1EqualDate2(Date1, Date2))
            return clsDate::enDateCompare::Equal;

        return clsDate::enDateCompare::After;
    }

    static bool IsDateInPeriod(clsPeriod Period, clsDate Date)
    {

        return !(
            CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before ||
            CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After

            );
    }

    bool IsDateInPeriod(clsDate Date)
    {
        return IsDateInPeriod(*this, Date);
    }

    static bool IsOverLapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        if (
            CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before ||
            CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After)
            return false;
        {
            return true;
        }
    }

    static bool IsDateInPeriod(clsDate Date, clsPeriod Period)
    {

        return !(
            CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before ||
            CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After

            );
    }

    static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
    {

        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;

        if (!IsOverLapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {
            while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate) || clsDate::IsDate1EqualDate2(Period1.StartDate, Period1.EndDate))
            {
                if (IsDateInPeriod(Period1.StartDate, Period2))
                    OverlapDays++;
                Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
            }
        }
        else
        {
            while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate) || clsDate::IsDate1EqualDate2(Period1.StartDate, Period1.EndDate))
            {
                if (IsDateInPeriod(Period2.StartDate, Period1))
                    OverlapDays++;
                Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
            }
        }
        return OverlapDays;
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();

        cout << "Period End: ";
        EndDate.Print();
    }
};