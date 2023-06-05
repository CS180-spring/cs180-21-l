import * as React from "react";
import { EmptyState, ListDetailViewIcon } from "evergreen-ui";

// This is a placeholder component for the main content area
// Represents the main content area of the application when no document is open
export default function EmptyMain() {
  return (
    <EmptyState
      background="dark"
      title="Open a document from the sidebar to get started"
      orientation="horizontal"
      icon={<ListDetailViewIcon color="#EBAC91" />}
      description="You can open a document by clicking on it in the sidebar."
      iconBgColor="#F8E3DA"
    />
  );
}
