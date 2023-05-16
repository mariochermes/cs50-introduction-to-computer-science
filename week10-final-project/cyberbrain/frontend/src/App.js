import { BrowserRouter , Routes, Route } from 'react-router-dom';
import Layout from './Layout';
import HomePage from './pages/HomePage';

export default function App() {
  return (
    <>
      <BrowserRouter>
        <Layout>
          <Routes>
            <Route path="/" element={<HomePage />} />
          </Routes>
        </Layout>
      </BrowserRouter>
    </>
  );
}
