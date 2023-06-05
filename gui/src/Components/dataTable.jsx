import * as React from "react";
import { Table, toaster } from "evergreen-ui";
import { useJSONFilePath } from "../Contexts/JSONFilePathContext";

export default function DataTable({ refresh }) {
  const [searchQuery, setSearchQuery] = React.useState("");
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

  const handleRefresh = () => {
    refresh(); // Call the refresh prop function to re-read the JSON file
  };

  const sortedData = sortData().filter((row) => {
    return Object.values(row).some(
      (value) =>
        String(value).toLowerCase().indexOf(searchQuery.toLowerCase()) !== -1
    );
  });

  return (
    <Table>
      <Table.Head>
        <Table.SearchHeaderCell
          placeholder="Search Items..."
          onChange={(e) => setSearchQuery(e)}
          value={searchQuery}
        />
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
