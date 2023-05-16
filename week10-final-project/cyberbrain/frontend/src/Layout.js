import React from 'react';
import NavigationBar from './components/NavigationBar';

export default function Layout({ children }) {
  return (
    <>
      <header>
        <NavigationBar></NavigationBar>
      </header>
      <main className="h-100">{children}</main>
    </>
  );
};
