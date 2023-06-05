import * as React from "react";
import { Table, EmptyState, DatabaseIcon, toaster } from "evergreen-ui";
import { useJSONFilePath } from "../Contexts/JSONFilePathContext";

export default function DataTable() {
  const { filePath, setFilePath } = useJSONFilePath();
  const [fileData, setFileData] = React.useState(null);
  const [sorting, setSorting] = React.useState({
    column: "",
    direction: "asc",
  });

  const handleFileData = React.useCallback((data) => {
    console.log(JSON.parse(data));
    setFileData(JSON.parse(data));
  }, []);

  // Function to fetch file data
  const fetchFileData = () => {
    if (filePath !== "") {
      window.electronAPI.readFile(filePath);
    }
  };

  // Call fetchFileData when filePath changes
  React.useEffect(() => {
    fetchFileData();
  }, [filePath]);

  // Call handleFileData when file data is received
  React.useEffect(() => {
    window.electronAPI.onReadFileReply(handleFileData);
  }, [handleFileData]);

  // Copy ID to clipboard
  const copytoClipboard = (value) => {
    navigator.clipboard
      .writeText(value)
      .then(() => {
        //console.log("Value copied to clipboard:", value);
        toaster.notify("Copied value (" + value + ") to clipboard!");
      })
      .catch((error) => {
        console.error("Failed to copy value to clipboard:", error);
        toaster.danger("Failed to copy value to clipboard!");
      });
  };

  const handleSort = (column) => {
    const direction =
      sorting.column === column && sorting.direction === "asc" ? "desc" : "asc";
    setSorting({ column, direction });
    toaster.notify("Sorting by " + column + " in " + direction + " order");
  };

  const sortData = () => {
    if (fileData) {
      const { column, direction } = sorting;
      const sortedData = [...fileData].sort((a, b) => {
        if (a[column] < b[column]) return direction === "asc" ? -1 : 1;
        if (a[column] > b[column]) return direction === "asc" ? 1 : -1;
        return 0;
      });
      return sortedData;
    }
    return [];
  };

  const sortedData = sortData();

  return (
    <Table>
      <Table.Head>
        <Table.SearchHeaderCell placeholder="Search Items..." />
      </Table.Head>
      <Table.Head>
        {fileData &&
          Object.keys(fileData[0]).map((key) => (
            <Table.TextHeaderCell
              key={key}
              onClick={() => handleSort(key)}
              isSortable
              sortOrder={sorting.column === key ? sorting.direction : null}
              cursor="grab"
            >
              {key}
            </Table.TextHeaderCell>
          ))}
      </Table.Head>
      <Table.Body height="auto" backgroundColor="white">
        {sortedData.map((row, index) => (
          <Table.Row
            key={index}
            isSelectable
            onSelect={() => copytoClipboard(Object.values(row)[0])}
          >
            {Object.values(row).map((value, i) => (
              <Table.TextCell key={i}>{value}</Table.TextCell>
            ))}
          </Table.Row>
        ))}
      </Table.Body>
    </Table>
  );
}

/*
        <EmptyState
          background="light"
          title="No Data in this Document"
          orientation="horizontal"
          icon={<DatabaseIcon color="#C1C4D6" />}
          iconBgColor="#EDEFF5"
          description="This document is empty. Add some data to it!"
        />
*/
