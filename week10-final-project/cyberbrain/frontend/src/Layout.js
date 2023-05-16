import React from 'react';
import NavigationBar from './components/NavigationBar';

export default function Layout({ children }) {
  return (
    <>
      <header>
        <NavigationBar></NavigationBar>
      </header>
      <main>{children}</main>
    </>
  );
};
