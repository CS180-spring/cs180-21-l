import * as React from "react";
import { Table, EmptyState, DatabaseIcon } from "evergreen-ui";

export default function DataTable(props) {
  return (
    <Table>
      <Table.Head>
        <Table.SearchHeaderCell />
      </Table.Head>
      <Table.Body height="auto" backgroundColor="white">
        <EmptyState
          background="light"
          title="No Data in this Document"
          orientation="horizontal"
          icon={<DatabaseIcon color="#C1C4D6" />}
          iconBgColor="#EDEFF5"
          description="This document is empty. Add some data to it!"
        />
      </Table.Body>
    </Table>
  );
}
