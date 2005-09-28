/*
 * Copyright (C) 2005 National Association of REALTORS(R)
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 */

#ifndef LIBRETS_SEARCH_RESULT_SET_H
#define LIBRETS_SEARCH_RESULT_SET_H

#include <string>
#include <vector>
#include "librets/std_forward.h"
#include "librets/RetsObject.h"

namespace librets {

class SearchResultSetImpl;
/** Smart pointer to SearchResultSetImpl. */
typedef boost::shared_ptr<SearchResultSetImpl> SearchResultSetImplPtr;

/**
 * A search result set.
 */
class SearchResultSet : public virtual RetsObject
{
  public:
    /**
     * Default constructor.
     */
    SearchResultSet();

    void Parse(istreamPtr inputStream);

    /**
     * Returns true if there are more results.  This may block waiting
     * for data from the RETS server.
     */
    bool HasNext();

    /**
     * Returns the number of rows in the result set, or -1 if not
     * known.  The number of rows is only available if it was
     * specified in the SearchRequest.
     *
     * @return The number of rows, or -1
     */
    int GetCount();

    /**
     * Returns the column names.
     *
     * @return The column names
     */
    StringVectorPtr GetColumns();

    /**
     * Returns the value of a column as a string.
     *
     * @param columnIndex column index
     * @return string value of column
     */
    std::string GetString(int columnIndex);

    /**
     * Returns the value of a column as a string.
     *
     * @param columnName column name
     * @return string value of column
     */
    std::string GetString(std::string columnName);

  private:
    SearchResultSetImplPtr mImpl;
};

};

#endif

/* Local Variables: */
/* mode: c++ */
/* End: */
