import * as React from "react";
import { Table, EmptyState, DatabaseIcon } from "evergreen-ui";
import { useJSONFilePath } from "../Contexts/JSONFilePathContext";

export default function DataTable() {
  const { filePath, setFilePath } = useJSONFilePath();
  const [fileData, setFileData] = React.useState(null);

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

  return (
    <Table>
      <Table.Head>
        <Table.SearchHeaderCell placeholder="Search Items..." />
      </Table.Head>
      <Table.Head>
        {fileData &&
          Object.keys(fileData[0]).map((key) => (
            <Table.TextHeaderCell key={key}>{key}</Table.TextHeaderCell>
          ))}
      </Table.Head>
      <Table.Body height="auto" backgroundColor="white">
        {fileData &&
          fileData.map((row, index) => (
            <Table.Row key={index}>
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
